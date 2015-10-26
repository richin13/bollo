//
// Created by ricardo on 24/10/15.
//


#include <QtCore/qjsondocument.h>
#include "http.h"

/**
 * @brief Builds a new URL to make a request to it.
 * @param section API section to use in the URL.
 * @param module API module to use in the URL.
 * @param args QHash that contains the parameters of the url query.
 *
 */
QUrl* url_builder(QString section, QString module, QHash<QString, QString>& args) {
    QString base_url = QString("%1%2/%3/%4.php").arg(WEB_HOST).arg(API_PATH).arg(section).arg(module);
    QUrl* url(new QUrl(base_url));
    QUrlQuery url_query;
    QHashIterator<QString, QString> i(args);

    while(i.hasNext()) {
        i.next();
        url_query.addQueryItem(i.key(), i.value());
    }

    url->setQuery(url_query);
    return url;
}

