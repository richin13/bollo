//
// Created by ricardo on 12/10/15.
//

#include <QtCore/qjsonobject.h>
#include <QtWidgets/qmessagebox.h>
#include "logindialog.h"
#include "../io/sql.h"
#include "../io/http.h"

LoginDialog::LoginDialog(QWidget* parent) :
        QDialog(parent),
        ui(new Ui::LoginDialog), manager(new QNetworkAccessManager(this)) {
    ui->setupUi(this);
}

LoginDialog::~LoginDialog() {
    delete ui;
    delete manager;
    cout << "Deleted all" << endl;
}

void LoginDialog::on_qb_exit_clicked() {
    this->close();
}

void LoginDialog::on_qb_login_clicked() {
    QString username = ui->qle_username->text();
    QByteArray password = ui->qle_password->text().toUtf8();

    this->user_id = login(username, password);

    if(this->user_id) {
        //Build the URL
        QHash<QString, QString> args;
        args["id"] = QVariant(user_id).toString();
        QUrl* url = url_builder("users", "user", args);//Looks like this-> .../api/v1/users/user.php?id=user_id

        connect(manager, &QNetworkAccessManager::finished, this, &LoginDialog::gotReply);

        //Send request using GET method. TODO: GET or POST? Maybe POST in the future.
        manager->get(QNetworkRequest(*url));
    } else {
        QMessageBox::critical(this, "Datos incorrectos", "Usuario/Contraseña incorrectos. Intente de nuevo");
        cerr << "Error login! Check your credentials" << endl;
    }
}

void LoginDialog::gotReply(QNetworkReply* reply) {
    qDebug() << "Got reply from server!";
    QJsonObject object = QJsonDocument::fromJson((reply->readAll())).object();//This looks disgusting
    int code = object.take("code").toInt(); //Take the response code!
    if(!code) {//It was previously checked that the user exists!
        QJsonObject person = object.take("user").toObject();

        int id = person.take("id").toInt();
        QString fn = person.take("first_name").toString();
        QString ln = person.take("last_name").toString();
        QString un = person.take("username").toString();
        QString email = person.take("email").toString();

        BolloApp::get().current_user = new Person(id, fn, ln, un, email);
        this->close();
    }
}
