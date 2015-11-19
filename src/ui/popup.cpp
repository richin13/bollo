/**
 * @author Daniel Aguilar, Ricardo Madriz
 *
 * Simple wrapper used to make notifications to the user with libnotify library.
 * A system call is made to the system, since this app is linux only we used this
 * method in order to use less dependencies, since the libnotify library for C++
 * it's not installed by default in most linux distros.
 */
#include <src/core/bollo_constants.h>
#include "popup.h"
#include "../io/telebot.h"

void sendNotification(string title, string msg, string icon) {

    string cmd = "notify-send '" + title + "' '" + msg + "' --icon=" + icon;

    // Send notification with tele bot to user.
    string botMessage = title + "\n---------\n" + msg;
    TeleBot::sendMessage(Constants::BOLLOBOT_CHAT_ID, botMessage);

    if(system(cmd.c_str())) {

        LOG(WARNING) << "An error ocurred while showing the event notification";
    }
}

void sendInfoNotification(string title, string msg) {
    sendNotification(title, msg, "dialog-information");
}

void sendWarningNotification(string title, string msg) {
    sendNotification(title, msg, "dialog-warning");
}

void sendQuestionNotification(string title, string msg) {
    sendNotification(title, msg, "dialog-question");
}