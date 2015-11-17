//
// Created by ricardo on 11/10/15.
//

#include "bollo.h"

/**
 * @brief Class constructor.
 */
BolloApp::BolloApp() {
    updater = new StatusUpdater();
    //TODO: Add a splash screen to make the whole process more user-friendly

    /* The app settings stored at home directory */
    init_settings();

    /* Fetch the information of the bakeries through the API - What happens when somebody adds a new bakery? */
    load_bakeries();

    /* Object connections */
    connect(this, &BolloApp::destroyed, this, &BolloApp::deleteLater);
}

/**
 * @brief Class destructor.
 */
BolloApp::~BolloApp() {
    LOG(DEBUG) << "Freeing allocated objects in BolloApp class";

    delete current_user;

    delete updater;
    ministry->stop();

    ulong size = bakeries.size();

    for(ulong i = 0; i < size; ++i) {
        Bakery* b = bakeries.at(i);
        delete b;
    }

    delete ministry;
}

/**
 * @brief Method that sends a GET request to the API server
 * in order the fetch the information of the bakeries stored
 * at the database.
 */
void BolloApp::load_bakeries() {
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

/**
 * @brief Slot invoked once the information of the bakeries have arrived
 * from API server.
 * @param reply Object that contains the response information.
 */
void BolloApp::loaded_bakeries(QNetworkReply* reply) {
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

/**
 * @brief Method used to start the execution of every individual bakery.
 */
void BolloApp::start_bakeries() {
    LOG(INFO) << "Starting bakeries";
    int size = (int) bakeries.size();

    for(unsigned long i = 0; i < size; ++i) {
        bakeries.at(i)->start();
    }

    init_ministry();
}

/**
 * @brief Method used to start the execution of the 'Ministry of health'
 *  thread.
 */
void BolloApp::init_ministry() {
    LOG(INFO) << "Starting ministry thread";
    ministry = new Ministry;
    ministry->start();
}

/**
 * @brief Method used to connect the status updater with every bakery.
 */
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

/**
 * @brief Gets the literal name of a given bakery.
 * @param id The bakery id
 * @return the name of the bakery with the id provided.
 */
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

/**
 * @brief Singletton pattern.
 * @return A copy of this instance.
 */
BolloApp& BolloApp::get() {
    static BolloApp instance;
    return instance;
}
