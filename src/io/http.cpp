//
// Created by ricardo on 24/10/15.
//


#include <QtCore/qjsondocument.h>
#include "http.h"
#include "../logger/easylogging++.h"

/**
 * @brief Builds a new URL to make a request to it.
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
    LOG(DEBUG) << "Built URL: " + url.toString().toStdString();

}

void extract_json_object(QNetworkReply* rep, QJsonObject * json) {
    *json = QJsonDocument::fromJson(rep->readAll()).object();
}
