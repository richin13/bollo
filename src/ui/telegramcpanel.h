#ifndef TELEGRAMCPANEL_H
#define TELEGRAMCPANEL_H

#include <QDialog>

namespace Ui {

class TelegramCpanel;
}

class TelegramCpanel : public QDialog {
    Q_OBJECT

public:
    explicit TelegramCpanel(QWidget *parent = 0);
    ~TelegramCpanel();

private slots:
    void on_sendButton_clicked();
    void on_chatIDInput_returnPressed();

private:
    Ui::TelegramCpanel *ui;

    void sendConfirmation(int chatId);
    void registerIntoDataBase(int chatId);
};

#endif // TELEGRAMCPANEL_H
