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
#include "../logger/logger.h"

BolloApp::BolloApp() {
    this->app_dir = new QDir(QDir().homePath() + "/bollo");
    this->manager = new QNetworkAccessManager(this);
    //TODO: Add a splash screen to make the whole process more user-friendly

    /* The app settings stored at home directory */
    init_settings();

    /* The database connection - Only need to be done once */
    init_database();

    load_bakeries_from_db();

    /* Object connections */
    connect(this, &BolloApp::destroyed, this, &BolloApp::deleteLater);
    connect(this, &BolloApp::destroyed, &logbook, &Logger::deleteLater);
}

BolloApp::~BolloApp() {
    LOG(DEBUG) << "Freeing allocated objects in BolloApp class";
    delete app_dir;
    delete manager;
    delete current_user;
}

void BolloApp::init_settings(void) {
    LOG(INFO) << "Loading Bollo settings";
    QString absolute_path = this->app_dir->absolutePath();

    if(!this->app_dir->exists()) {
        QDir().mkdir(absolute_path);
        load_default_settings();
    } else {
        QFileInfo config_file = QFileInfo(config_file_path());
        if(!config_file.exists()) {
            LOG(INFO) << "Settings file not found, creating default...";
            load_default_settings();
            LOG(INFO) << "Settings file created";
        } else {
            LOG(INFO) << "Settings file found";
            load_settings();
        }
    }
}

void BolloApp::load_default_settings(void) {
    QString fullPath = config_file_path();

    if(QFile::exists(fullPath)) {
        QFile::remove(fullPath);
    }

    QSettings bollo_settings(fullPath, QSettings::NativeFormat);

    /* Networking settings */
    bollo_settings.beginGroup(QStringLiteral("Networking"));
    bollo_settings.setValue(QStringLiteral("host_url"), QVariant(""));
    bollo_settings.setValue(QStringLiteral("api_path"), QVariant(""));
    bollo_settings.endGroup();

    /* Db settings */
    bollo_settings.beginGroup(QStringLiteral("Database"));
    bollo_settings.setValue(QStringLiteral("db_host"), QVariant(""));
    bollo_settings.setValue(QStringLiteral("db_user"), QVariant(""));
    bollo_settings.setValue(QStringLiteral("db_pass"), QVariant(""));
    bollo_settings.setValue(QStringLiteral("db_schema"), QVariant(""));
    bollo_settings.endGroup();

    /* General operations settings */
    bollo_settings.beginGroup(QStringLiteral("Operations"));
    bollo_settings.setValue(QStringLiteral("average_production"), QVariant(55));
    bollo_settings.setValue(QStringLiteral("dough_per_batch"), QVariant(15));
    bollo_settings.setValue(QStringLiteral("poll_probability"), QVariant(10));
    bollo_settings.setValue(QStringLiteral("badyeast_probability"), QVariant(10));//Man, this is hard
    bollo_settings.endGroup();
}

void BolloApp::load_settings(void) {
    QString cf_path = config_file_path();

    if(!QFile::exists(cf_path)) {
        throw std::exception();
    }

    QSettings bollo_settings(cf_path, QSettings::NativeFormat);

    /* Networking settings */
    bollo_settings.beginGroup(QStringLiteral("Networking"));
    Constants::API_HOST = bollo_settings.value("host_url").toString();
    Constants::API_PATH = bollo_settings.value("api_path").toString();
    bollo_settings.endGroup();

    /* Db settings */
    bollo_settings.beginGroup(QStringLiteral("Database"));
    Constants::DB_HOST = bollo_settings.value("db_host").toString();
    Constants::DB_USERNAME = bollo_settings.value("db_user").toString();
    Constants::DB_PASSWORD = bollo_settings.value("db_pass").toString();
    Constants::DB_SCHEME = bollo_settings.value("db_schema").toString();
    bollo_settings.endGroup();

}

void BolloApp::init_database(void) {
    LOG(INFO) << "Starting database server connection";
    this->bollo_db = QSqlDatabase::addDatabase("QPSQL");
    bollo_db.setHostName(Constants::DB_HOST);
    bollo_db.setDatabaseName(Constants::DB_SCHEME);
    bollo_db.setUserName(Constants::DB_USERNAME);
    bollo_db.setPassword(Constants::DB_PASSWORD);

    if(!bollo_db.open()) {
        LOG(FATAL) << "Unable to reach the database server";
        QMessageBox::critical(QApplication::activeWindow(),
                              "Revisa tu conexión a Internet",
                              "Ocurrió un error mientras intentabámos comunicarnos con el servidor de base de datos.");
    }
}

void BolloApp::load_bakeries_from_db() {
    LOG(DEBUG) << "Loading bakeries through web API";

    //Request all
    QHash<QString, QString> args;
    args["all"];
    QUrl url;
    url_builder(url, "bakeries", "bakery", args);
    LOG(INFO) << "Sending GET request to " + url.toString().toStdString();

    QObject::connect(manager, &QNetworkAccessManager::finished, this, &BolloApp::loaded_bakeries);
    manager->get(QNetworkRequest(url));
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

    QObject::connect(reply, &QNetworkReply::finished, reply, &QNetworkReply::deleteLater);
}

QString BolloApp::windowTittle() {
    return QString("%1-[%2]_%3").arg(APP_NAME, CODENAME, VERSION);
}

BolloApp& BolloApp::get() {
    static BolloApp instance;
    return instance;
}

QString BolloApp::config_file_path() const {
    return QString(app_dir->absolutePath() + "/settings/bollo.ini");
}

void BolloApp::set_setting(const QString& group, const QString& key, const QVariant& value) {
    static QString cf_path = config_file_path();
    static QSettings bollo_settings(cf_path, QSettings::NativeFormat);

    bollo_settings.beginGroup(group);
    bollo_settings.setValue(key, value);
    bollo_settings.endGroup();
}

QVariant BolloApp::get_setting(const QString& group, const QString& key) {
    static QString cf_path = config_file_path();
    static QSettings bollo_settings(cf_path, QSettings::NativeFormat);

    bollo_settings.beginGroup(group);
    QVariant result = bollo_settings.value(key);
    bollo_settings.endGroup();

    return result;
}
