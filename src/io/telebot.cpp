//
// Created by Daniel on 14/11/15.
//

#include "telebot.h"

void TeleBot::sendMessage(int chatId, std::string message) {

    QNetworkAccessManager* manager = new QNetworkAccessManager();

    //Build the URL
    QHash<QString, QString> args;
    args["token"] = Constants::BOLLOBOT_TOKEN;
    args["chatid"] = QString::number(chatId);
    args["msg"] = QString(message.c_str());

    QUrl url;
    url_builder(url, "bakeries", "notifier", args);

    connect(manager, &QNetworkAccessManager::finished, manager, &QNetworkAccessManager::deleteLater);
    manager->get(QNetworkRequest(url));
}