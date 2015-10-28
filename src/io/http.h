//
// Created by ricardo on 24/10/15.
//

#ifndef BOLLO_HTTP_H
#define BOLLO_HTTP_H

#include <QtCore/qstring.h>
#include <QtNetwork/qnetworkaccessmanager.h>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

#include <QtCore/qjsonobject.h>
#include <QtCore/qurl.h>
#include <QtCore/qurlquery.h>

#include "../core/bollo.h"


QUrl* url_builder(QString section, QString module, QHash<QString, QString>& args);
void extract_json_object(QNetworkReply*, QJsonObject*);


#endif //BOLLO_HTTP_H
