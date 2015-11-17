//
// Created by ricardo on 24/10/15.
//


#include "http.h"

/**
 * Builds a new URL to make a request to it.
 * @param section API section to use in the URL.
 * @param module API module to use in the URL.
 * @param args QHash that contains the parameters of the url query.
 *
 */
void url_builder(QUrl& url, QString section, QString module, QHash<QString, QString>& args) {
    QString base_url = QString("%1%2/%3/%4.php").arg(Constants::API_HOST).arg(Constants::API_PATH).arg(section).arg(
            module);
    QUrlQuery url_query;
    url.setUrl(base_url);
    QHashIterator<QString, QString> i(args);
    while(i.hasNext()) {
        i.next();
        url_query.addQueryItem(i.key(), i.value());
    }

    url.setQuery(url_query);

}

/**
 * Extracts the json object from a server response/reply.
 * @param rep Server raw reply.
 * @param json Pointer to a JsonObject where the information will be stored.
 */
void extract_json_object(QNetworkReply* rep, QJsonObject* json) {
    *json = QJsonDocument::fromJson(rep->readAll()).object();
}

/**
 * Slot used to update the bakery status by sending a GET request
 * to the API server.
 * @param op The operation information.
 */
void StatusUpdater::updater(_operation op) {
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    QHash<QString, QString> args;
    args["id"] = QString::number(op.bakery_id);
    args["progress"] = QString::number(op.progress);
    args["description"] = op.description;

    QUrl url;
    url_builder(url, "bakeries", "status", args);
    QObject::connect(manager, &QNetworkAccessManager::finished, this, &StatusUpdater::notifier);
    QObject::connect(manager, &QNetworkAccessManager::finished, manager, &QNetworkAccessManager::deleteLater);

    manager->get(QNetworkRequest(url));

    if(op.progress / 100 > 4) stock_updater(op);
}

/**
 * Slot used to send the stock information of a bakery to the API
 *  server.
 *  @para op The current operation information.
 */
void StatusUpdater::stock_updater(_operation op) {
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    QHash<QString, QString> args;
    args["id"] = QString::number(op.bakery_id);
    args["stock"] = QString::number(op.stock);

    QUrl url;
    url_builder(url, "bakeries", "bakery", args);
    QObject::connect(manager, &QNetworkAccessManager::finished, this, &StatusUpdater::notifier);
    QObject::connect(manager, &QNetworkAccessManager::finished, manager, &QNetworkAccessManager::deleteLater);

    manager->get(QNetworkRequest(url));
}

/**
 * Slot used to report any API error comming from server response.
 * @reply Raw reply from server.
 */
void StatusUpdater::notifier(QNetworkReply* reply) {
    QJsonObject object;

    extract_json_object(reply, &object);
    int code = object.take("code").toInt();
    if(code) {
        LOG(WARNING) << "API returned with code " + std::to_string(code);
    }

    QObject::connect(reply, &QNetworkReply::finished, reply, &QNetworkReply::deleteLater);
}
