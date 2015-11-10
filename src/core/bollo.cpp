//
// Created by ricardo on 11/10/15.
//

#include "bollo.h"


BolloApp::BolloApp() {
    this->updater = new StatusUpdater();
    //TODO: Add a splash screen to make the whole process more user-friendly

    /* The app settings stored at home directory */
    init_settings();

    /* The database connection - Only need to be done once */
    init_database();

    /* Fetch the information of the bakeries through the API - What happens when somebody adds a new bakery? */
    load_bakeries_from_db();

    /* Object connections */
    connect(this, &BolloApp::destroyed, this, &BolloApp::deleteLater);
}

BolloApp::~BolloApp() {
    LOG(DEBUG) << "Freeing allocated objects in BolloApp class";
    emit application_exiting();
    delete current_user;
    delete updater;
    unsigned long size = bakeries.size();

    for(unsigned long i = 0; i < size; ++i) {
        bakeries.at(i)->terminate();
        bakeries.at(i)->wait();
        delete bakeries.at(i);
    }
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
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    //Request all
    QHash<QString, QString> args;
    args["all"];
    QUrl url;
    url_builder(url, "bakeries", "bakery", args);
    LOG(INFO) << "Sending GET request to " + url.toString().toStdString();

    QObject::connect(manager, &QNetworkAccessManager::finished, this, &BolloApp::loaded_bakeries);
    QObject::connect(manager, &QNetworkAccessManager::finished, manager, &QNetworkAccessManager::deleteLater);
    manager->get(QNetworkRequest(url));
}

void BolloApp::loaded_bakeries(QNetworkReply* reply) {
    LOG(INFO) << "Got reply from server: Load bakeries";
    QJsonObject jsonObject;

    extract_json_object(reply, &jsonObject);

    if(!jsonObject.take("code").toInt()) {
        QJsonArray array = jsonObject.take("bakeries").toArray();
        Handler::get_bakeries_vector(&bakeries, &array);
    } else {
        LOG(WARNING) << "Error code in response: " + jsonObject.take("message").toString().toStdString();
    }
    init_updater();
    start_bakeries();
    QObject::connect(reply, &QNetworkReply::finished, reply, &QNetworkReply::deleteLater);
}

void BolloApp::start_bakeries() {
    LOG(INFO) << "Starting bakeries";
    int size = (int) bakeries.size();

    for(unsigned long i = 0; i < size; ++i) {
        bakeries.at(i)->start();
    }
    LOG(DEBUG) << "Started bakeries";
}

void BolloApp::init_updater() {
    LOG(DEBUG) << "Initialization of status updater";
    int size = (int) bakeries.size();

    for(unsigned long i = 0; i < size; ++i) {
        Bakery* b = bakeries.at(i);
        QObject::connect(b,
                         &Bakery::operation_changed,
                         updater,
                         &StatusUpdater::updater);
    }
}

const QString& BolloApp::get_bakery_name(int id) {
    int size = (int) bakeries.size();

    for(int i = 0; i < size; ++i) {
        Bakery* current = bakeries.at((unsigned long) i);
        if(current->get_id() == id) {
            return current->get_name();
        }
    }

    return QStringLiteral("Not found");//Should never happen.
}

QString BolloApp::windowTittle() {
    return QString("%1-[%2]_%3").arg(APP_NAME, CODENAME, VERSION);
}

BolloApp& BolloApp::get() {
    static BolloApp instance;
    return instance;
}
