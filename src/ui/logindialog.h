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
#include <QtCore/qjsonobject.h>
#include <QtWidgets/qmessagebox.h>

#include "../core/bollo.h"
#include "assets.h"
#include "ui_headers/ui_logindialog.h"

namespace Ui {
    class LoginDialog;
}

class LoginDialog : public QDialog {
Q_OBJECT

public:
    explicit LoginDialog(QWidget* parent = 0);

    ~LoginDialog();

public slots:

    void on_qb_exit_clicked();

    void on_qb_login_clicked();

    void got_login_reply(QNetworkReply*);

signals:
    void logged_in();

private:
    Ui::LoginDialog* ui;
    int user_id;
};

#endif //BOLLO_LOGINDIALOG_H
