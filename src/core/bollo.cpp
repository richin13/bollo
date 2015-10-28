//
// Created by ricardo on 11/10/15.
//


#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/qapplication.h>
#include <QtNetwork/qnetworkaccessmanager.h>
#include <QtCore/qjsondocument.h>
#include <QtCore/qjsonarray.h>
#include "bollo.h"
#include "../logger/easylogging++.h"
#include "../io/http.h"
#include "../io/handler.h"

BolloApp::BolloApp() {
    this->app_dir = new QDir(QDir().homePath() + "/bollo");
    this->manager = new QNetworkAccessManager(this);
    //TODO: Add a splash screen to make the whole process more user-friendly
    /* The database connection - Only need to be done once */
    init_database();

    /* The app settings stored at home directory */
    init_settings();

    load_bakeries_from_db();

    /* Object connections */
    connect(this, &BolloApp::destroyed, this, &BolloApp::deleteLater);
}

BolloApp::~BolloApp() {
    LOG(DEBUG) << "Freeing allocated objects in BolloApp class";
    delete app_dir;
    delete manager;
    delete current_user;
}

void BolloApp::init_database(void) {
    LOG(INFO) << "Starting database server connection";
    this->bollo_db = QSqlDatabase::addDatabase("QPSQL");
    bollo_db.setHostName(HOST);
    bollo_db.setDatabaseName(SCHEMA);
    bollo_db.setUserName(USER);
    bollo_db.setPassword(PASSWORD);

    if(!bollo_db.open()) {
        LOG(FATAL) << "Unable to reach the database server";
        QMessageBox::critical(QApplication::activeWindow(),
                              "Unable to connect to the database server",
                              "An error occurred while trying to reach the PosgreSQL server");
    }
}

//TODO: Load bakeries from DB >> Assigned to @Castle0721

void BolloApp::init_settings(void) {
    QString absolute_path = this->app_dir->absolutePath();

    if(!this->app_dir->exists()) {
        QDir().mkdir(absolute_path);
        load_default_settings();
    } else {
        QFileInfo config_file = QFileInfo(absolute_path + "/settings/bollo.ini");
        if(!config_file.exists()) {
            load_default_settings();
        }
    }
}

void BolloApp::load_default_settings(void) {
    QString fullPath = this->app_dir->absolutePath() + "/settings/bollo.ini";

    if(QFile::exists(fullPath)) {
        QFile::remove(fullPath);
    }

    QFileInfo config_file = QFileInfo(fullPath);
    QSettings bollo_settings(config_file.absoluteFilePath(), QSettings::NativeFormat);

    /* Networking settings */
    bollo_settings.beginGroup(QStringLiteral("Networking"));
    bollo_settings.setValue(QStringLiteral("host_url"), QVariant(WEB_HOST));
    bollo_settings.setValue(QStringLiteral("api_path"), QVariant(API_PATH));
    bollo_settings.endGroup();

    /* Db settings */
    bollo_settings.beginGroup(QStringLiteral("Database"));
    bollo_settings.setValue(QStringLiteral("db_host"), QVariant(HOST));
    bollo_settings.setValue(QStringLiteral("db_user"), QVariant(USER));
    bollo_settings.setValue(QStringLiteral("db_pass"), QVariant(PASSWORD));
    bollo_settings.setValue(QStringLiteral("db_schema"), QVariant(SCHEMA));
    bollo_settings.endGroup();
}

void BolloApp::load_bakeries_from_db() {
    LOG(DEBUG) << "Loading bakeries through web API";

    //Request all
    QHash<QString, QString> args;
    args["all"];
    QUrl* url = url_builder("bakeries", "bakery", args);
    LOG(INFO) << "Sending GET request to " + url->toString().toStdString();

    connect(manager, &QNetworkAccessManager::finished, this, &BolloApp::loaded_bakeries);
    manager->get(QNetworkRequest(*url));
}

void BolloApp::loaded_bakeries(QNetworkReply* reply) {
    LOG(INFO) << "Got reply from server";
    QJsonObject jsonObject;

    extract_json_object(reply, &jsonObject);

    if(!jsonObject.take("code").toInt()) {
        QJsonArray array = jsonObject.take("bakeries").toArray();
        Handler::get_bakeries_vector(&array);

        LOG(INFO) << "Loaded bakeries: " + std::to_string(BolloApp::get().bakeries.size());
    } else {
        LOG(WARNING) << "Error code in response " + jsonObject.take("message").toString().toStdString();
    }

    connect(reply, &QNetworkReply::finished, reply, &QNetworkReply::deleteLater);
}

QString BolloApp::windowTittle() {
    return QString("%1-[%2]_%3").arg(APP_NAME, CODENAME, VERSION);
}

BolloApp& BolloApp::get() {
    static BolloApp instance;
    return instance;
}