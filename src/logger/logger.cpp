//
// Created by ricardo on 05/10/15.
//

#include "logger.h"

void Logger::send_logbook_entry(int bid, QString txt) {
    LOG(DEBUG) << "Sending new logbook entry: " + txt.toStdString();
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    //Build the url
    QHash<QString, QString> args;
    args["id"] = QString::number(bid);
    args["message"] = txt;

    QUrl url;
    url_builder(url, "reports", "report", args);

    QObject::connect(manager, &QNetworkAccessManager::finished, manager, &QNetworkAccessManager::deleteLater);

    manager->get(QNetworkRequest(url));
    LOG(DEBUG) << "Sent: " + txt.toStdString();
}

void Logger::send_logbook_problem(int bid, QString txt, int dough) {
    LOG(DEBUG) << "Sending new logbook problem: " + txt.toStdString();
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    //Build the url
    QHash<QString, QString> args;
    args["id"] = QString::number(bid);
    args["message"] = txt;
    args["dough"] = QString::number(dough);

    QUrl url;
    url_builder(url, "reports", "report", args);

    QObject::connect(manager, &QNetworkAccessManager::finished, manager, &QNetworkAccessManager::deleteLater);

    manager->get(QNetworkRequest(url));
    LOG(DEBUG) << "Sent: " + txt.toStdString();
}
