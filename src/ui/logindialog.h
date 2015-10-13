//
// Created by ricardo on 12/10/15.
//

#ifndef BOLLO_LOGINDIALOG_H
#define BOLLO_LOGINDIALOG_H

#include <QDialog>
#include <QtNetwork/qnetworkaccessmanager.h>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtCore/qjsondocument.h>

#include "../core/bollo.h"
#include "ui_headers/ui_logindialog.h"

namespace Ui {
    class LoginDialog;
}

class LoginDialog : public QDialog {
Q_OBJECT

public:
    explicit LoginDialog(QWidget* parent = 0);

    ~LoginDialog();

private slots:

    void on_qb_exit_clicked();

    void on_qb_login_clicked();

    void gotReply(QNetworkReply*);

private:
    Ui::LoginDialog* ui;
    int user_id;
};

#endif //BOLLO_LOGINDIALOG_H
