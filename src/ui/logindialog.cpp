//
// Created by ricardo on 12/10/15.
//

#include <QtCore/qjsonobject.h>
#include <QtWidgets/qmessagebox.h>
#include "logindialog.h"
#include "../io/http.h"
#include "../logger/easylogging++.h"
#include "assets.h"

LoginDialog::LoginDialog(QWidget* parent) :
        QDialog(parent),
        ui(new Ui::LoginDialog) {

    ui->setupUi(this);
    ui->label->setPixmap(QPixmap(Ui::AVATAR_ICON));
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
    ui->qb_login->setEnabled(false);

    QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    //Build the URL
    QHash<QString, QString> args;
    args["user"] = username;
    args["password"] = password;
    args["bolloapp"];//To avoid creating a web session
    QUrl url;
    url_builder(url, "users", "login", args);

    connect(manager, &QNetworkAccessManager::finished, this, &LoginDialog::got_login_reply);
    connect(manager, &QNetworkAccessManager::finished, manager, &QNetworkAccessManager::deleteLater);
    manager->get(QNetworkRequest(url));
    LOG(INFO) << "Sent GET request to URL to API at section 'users' module 'login'";
}

void LoginDialog::got_login_reply(QNetworkReply* reply) {
    LOG(INFO) << "Got reply from server: Login request";
    QJsonObject object;

    extract_json_object(reply, &object);
    int code_reply = object.take("code").toInt();
    if(!code_reply) {
        QJsonObject person = object.take("user_details").toObject();

        int id = person.take("id").toInt();
        QString fn = person.take("first_name").toString();
        QString ln = person.take("last_name").toString();
        QString un = person.take("username").toString();
        QString email = person.take("email").toString();

        BolloApp::get().current_user = new Person(id, fn, ln, un, email);
        this->close();
        emit logged_in();
    } else {
        ui->qb_login->setEnabled(true);
        switch(code_reply) {
            case 1:
                QMessageBox::critical(this, "Cuenta inactiva", "La cuenta no ha sido activada.");
                LOG(WARNING) << "Inactive account";
                break;
            case 2:
                QMessageBox::critical(this, "Datos incorrectos", "Usuario/Contraseña incorrectos. Intente de nuevo");
                LOG(WARNING) << "Invalid user credentials";
                break;
            default:
                LOG(FATAL) << "Call a developer! Now! NOW! <> Invalid API parameters at 'login' in 'users'";
        }
    }

    connect(reply, &QNetworkReply::finished, reply, &QNetworkReply::deleteLater);
}
