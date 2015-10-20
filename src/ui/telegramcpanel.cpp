#include <QString>
#include <QDebug>

#include "telegramcpanel.h"
#include "ui_headers/ui_telegramcpanel.h"

TelegramCpanel::TelegramCpanel(QWidget *parent) : QDialog(parent),
    ui(new Ui::TelegramCpanel) {

    ui->setupUi(this);

    // Set line edit to numbers only
    ui->chatIDInput->setValidator(new QIntValidator(0, INT_MAX, this));
}

TelegramCpanel::~TelegramCpanel() {

    delete ui;
}

void TelegramCpanel::on_sendButton_clicked() {

    if (ui->chatIDInput->text() != "") {

        sendConfirmation(ui->chatIDInput->text().toInt());
    }
}

void TelegramCpanel::on_chatIDInput_returnPressed() {

    sendConfirmation(ui->chatIDInput->text().toInt());
}

/**
 * @brief TelegramCpanel::sendConfirmation Send confirmation to user.
 * @param chatId Unique chat identifier between User<->Bot
 *
 * Send a message to the given chatId, if the message is sended succesfully
 * the chatId is registered in the dataBase to the user by calling
 * registerInDataBase() function.
 */
void TelegramCpanel::sendConfirmation(int chatId) {


}

/**
 * @brief TelegramCpanel::registerInDataBase Register chat id with the bot
 * to the user.
 * @param chatId Unique chat identifier between User<->Bot
 *
 * Register the chat id to the user in the database.
 */
void TelegramCpanel::registerIntoDataBase(int chatId) {


}
