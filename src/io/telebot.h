//
// Created by Daniel on 14/11/15.
//

#ifndef BOLLO_TELEBOT_H
#define BOLLO_TELEBOT_H

#include <string>
#include <QtNetwork/qnetworkaccessmanager.h>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtCore/qjsondocument.h>
#include <QtCore/qjsonobject.h>

#include "../logger/easylogging++.h"
#include "../core/bollo_constants.h"
#include "http.h"

class TeleBot : QObject {

    Q_OBJECT

public:
    static void sendMessage(int chatId, std::string message);
};

#endif //BOLLO_TELEBOT_H
