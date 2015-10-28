//
// Created by ricardo on 12/10/15.
//

#include <QtCore/qjsonobject.h>
#include <QtWidgets/qmessagebox.h>
#include "logindialog.h"
#include "../io/sql.h"
#include "../io/http.h"
#include "../logger/easylogging++.h"

LoginDialog::LoginDialog(QWidget* parent) :
        QDialog(parent),
        ui(new Ui::LoginDialog) {
    ui->setupUi(this);
}

LoginDialog::~LoginDialog() {
    delete ui;
}

void LoginDialog::on_qb_exit_clicked() {
    this->close();
}

void LoginDialog::on_qb_login_clicked() {
    QString username = ui->qle_username->text();
    QByteArray password = ui->qle_password->text().toUtf8();
    LOG(INFO) << "Logging in user " + username.toStdString();
    this->user_id = login(username, password);

    if(this->user_id) {
        //Build the URL
        QHash<QString, QString> args;
        args["id"] = QVariant(user_id).toString();
        QUrl* url = url_builder("users", "user", args);//Looks like this-> .../api/v1/users/user.php?id=user_id

        connect(BolloApp::get().manager, &QNetworkAccessManager::finished, this, &LoginDialog::gotReply);

        //Send request using GET method. TODO: GET or POST? Maybe POST in the future.
        BolloApp::get().manager->get(QNetworkRequest(*url));
        LOG(INFO) << "Sent GET request to URL " + url->toString().toStdString();
    } else {
        QMessageBox::critical(this, "Datos incorrectos", "Usuario/Contraseña incorrectos. Intente de nuevo");
        LOG(WARNING) << "Invalid user credentials";
    }
}

void LoginDialog::gotReply(QNetworkReply* reply) {
    LOG(INFO) << "Got reply from server: User information request";
    QJsonObject object;

    extract_json_object(reply, &object);
    if(!object.take("code").toInt()) {//It was previously checked that the user exists!
        QJsonObject person = object.take("user").toObject();

        int id = person.take("id").toInt();
        QString fn = person.take("first_name").toString();
        QString ln = person.take("last_name").toString();
        QString un = person.take("username").toString();
        QString email = person.take("email").toString();

        BolloApp::get().current_user = new Person(id, fn, ln, un, email);
        this->close();
    }

    connect(reply, &QNetworkReply::finished, reply, &QNetworkReply::deleteLater);
}
