//
// Created by ricardo on 12/10/15.
//

#include <QtCore/qjsonobject.h>
#include <QtWidgets/qmessagebox.h>
#include "logindialog.h"
#include "../io/sql.h"

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

    this->user_id = bollo::query::login(username, password);

    if(this->user_id) {
        // FIXME: This manager must be a global, probably an independent class
        QNetworkAccessManager* manager = new QNetworkAccessManager(this);
        // FIXME: Call connect just once in the constructor: TODO
        connect(manager, &QNetworkAccessManager::finished, this, &LoginDialog::gotReply);
        QString url = QString("http://localhost/bollo_web/api/v1/users/user.php?id=%1&api_token=1").arg(this->user_id);
        cout << "ABOUT TO MAKE THE REQUEST" << endl;
        manager->get(QNetworkRequest(QUrl(url)));
    } else {
        QMessageBox::critical(this, "Datos incorrectos", "Usuario/Contraseña incorrectos. Intente de nuevo");
        cerr << "Error login! Check your credentials" << endl;
    }
}

void LoginDialog::gotReply(QNetworkReply* reply) {
    // TODO: set BolloApp::current_user with the information coming from the API.
    QJsonDocument data = QJsonDocument::fromJson((reply->readAll()));
    QJsonObject object = data.object();
    cout << "Never get here!" << endl;
    int code = object.take("code").toInt();
    if(!code) {//It was previously checked that the user exists!
        QJsonObject person = object.take("user").toObject();
        int id = person.take("id").toInt();
        QString fn = person.take("first_name").toString();
        QString ln = person.take("last_name").toString();
        QString un = person.take("username").toString();
        QString email = person.take("email").toString();

        BolloApp::current_user = new Person(id, fn, ln, un, email);
        this->hide();//Exitus xD
    }
}
