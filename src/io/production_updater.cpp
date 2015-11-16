//
// Created by ricardo on 14/11/15.
//

#include <QtNetwork/qnetworkaccessmanager.h>
#include <QtCore/qurl.h>
#include "production_updater.h"
#include "http.h"

void StockUpdater::updater(int bid, int quantity) {
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    //Build the url <- Have you noticed that you always write this stupid comment?
    QHash<QString, QString> args;
    args["id"] = QString::number(bid);
    args["quantity"] = QString::number(quantity);

    QUrl url;
    url_builder(url, "bakeries", "production", args);
    LOG(DEBUG) << "Built URL " + url.toString().toStdString();

    QObject::connect(manager, &QNetworkAccessManager::finished, manager, &QNetworkAccessManager::deleteLater);
    manager->get(QNetworkRequest(url));
}
