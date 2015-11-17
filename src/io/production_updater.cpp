//
// Created by ricardo on 14/11/15.
//

#include <QtNetwork/qnetworkaccessmanager.h>
#include <QtCore/qurl.h>
#include "production_updater.h"
#include "http.h"

/**
 * Slot used to send the production information about a bakery.
 *  It is invoked every time a batch of bread is baked. The information
 *  generated here is used by us in bollo_web to create the charts of
 *  bakery production.
 * @param bid Bakery id.
 * @param quantity The quantity of bread produced.
 */
void ProductionUpdater::updater(int bid, int quantity) {
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
