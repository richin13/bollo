//
// Created by ricardo on 30/10/15.
//


#include "logbookdialog.h"

LogbookDialog::LogbookDialog(QWidget* parent) :
        QDialog(parent),
        ui(new Ui::LogbookDialog()) {
    ui->setupUi(this);
    load_events();
    load_problems();
}

LogbookDialog::~LogbookDialog() {
    delete ui;
}

void LogbookDialog::on_qbClose_clicked() {
    this->close();
}

void LogbookDialog::load_events(int filtering) {
    LOG(DEBUG) << "Loading Logbook entries -> Events - Filtering: " + to_string(filtering);
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    //Build the url
    QHash<QString, QString> args;
    args["event"];

    if(filtering) {
        args["bakery"] = QVariant(filtering).toString();
    }

    QUrl url;
    url_builder(url, QStringLiteral("reports"), QStringLiteral("logbook"), args);
    QObject::connect(manager, &QNetworkAccessManager::finished, this, &LogbookDialog::loaded_events);
    QObject::connect(manager, &QNetworkAccessManager::finished, manager, &QNetworkAccessManager::deleteLater);

    manager->get(QNetworkRequest(url));
}

void LogbookDialog::load_problems(int filtering) {
    LOG(DEBUG) << "Loading Logbook entries -> Problems - Filtering: " + to_string(filtering);
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    //Build the url
    QHash<QString, QString> args;
    args["problem"];

    if(filtering) {
        args["bakery"] = QVariant(filtering).toString();
    }

    QUrl url;
    url_builder(url, QStringLiteral("reports"), QStringLiteral("logbook"), args);
    QObject::connect(manager, &QNetworkAccessManager::finished, this, &LogbookDialog::loaded_problems);
    QObject::connect(manager, &QNetworkAccessManager::finished, manager, &QNetworkAccessManager::deleteLater);

    manager->get(QNetworkRequest(url));
}

void LogbookDialog::loaded_events(QNetworkReply* reply) {
    LOG(INFO) << "Got reply from server: Load Logbook entries -> Events";
    QJsonObject object;

    extract_json_object(reply, &object);
    int code_reply = object.take("code").toInt();
    if(!code_reply) {
        QJsonArray events = object.take("events").toArray();
        setup_events(events);
    }

    QObject::connect(reply, &QNetworkReply::finished, reply, &QNetworkReply::deleteLater);
}

void LogbookDialog::setup_events(const QJsonArray& data) {
    int size = data.size();
    ui->qtGeneral->setRowCount(size);

    for(int i = 0; i < size; ++i) {
        QJsonObject current = data[i].toObject();
        ui->qtGeneral->setItem(i, 0, new QTableWidgetItem(QString::number(current.take("id").toInt())));
        QString bakery_name = BolloApp::get().get_bakery_name(current.take("bakery").toInt());
        ui->qtGeneral->setItem(i, 1, new QTableWidgetItem(bakery_name));
        ui->qtGeneral->setItem(i, 2, new QTableWidgetItem(current.take("description").toString()));
        ui->qtGeneral->setItem(i, 3, new QTableWidgetItem(current.take("date").toString()));
        ui->qtGeneral->setItem(i, 4, new QTableWidgetItem(current.take("hour").toString()));
    }
}

void LogbookDialog::loaded_problems(QNetworkReply* reply) {
    LOG(INFO) << "Got reply from server: Load Logbook entries -> Problems";
    QJsonObject object;

    extract_json_object(reply, &object);
    int code_reply = object.take("code").toInt();

    if(!code_reply) {
        QJsonArray problems = object.take(QStringLiteral("problems")).toArray();
        setup_problems(problems);
    }

    QObject::connect(reply, &QNetworkReply::finished, reply, &QNetworkReply::deleteLater);
}

void LogbookDialog::setup_problems(const QJsonArray& data) {
    int size = data.size();
    ui->qtProblem->setRowCount(size);
    std::cout << "Size: " << size << std::endl;
    for(int i = 0; i < size; ++i) {
        QJsonObject current = data[i].toObject();
        ui->qtProblem->setItem(i, 0, new QTableWidgetItem(QString::number(current.take("id").toInt())));
        QString bakery_name = BolloApp::get().get_bakery_name(current.take("bakery").toInt());
        ui->qtProblem->setItem(i, 1, new QTableWidgetItem(bakery_name));
        ui->qtProblem->setItem(i, 2, new QTableWidgetItem(current.take("description").toString()));
        ui->qtProblem->setItem(i, 3, new QTableWidgetItem(QString::number(current.take("dough").toInt())));
        ui->qtProblem->setItem(i, 4, new QTableWidgetItem(current.take("date").toString()));
        ui->qtProblem->setItem(i, 5, new QTableWidgetItem(current.take("hour").toString()));
    }

}