//
// Created by ricardo on 11/10/15.
//

#include <QtSql/qsqldatabase.h>
#include "bollo.h"

BolloApp::BolloApp(int argc, char** argv) : QApplication(argc, argv) {
    this->app_name = "Bollo";
    this->codename = "Ajonjoli";
    this->version = "0.0.1-build-10_1";//[version]-build-{MONTH_week}

    /* The database connection - Only need to be done once */
    QSqlDatabase bollo_db = QSqlDatabase::addDatabase("QPSQL");
    bollo_db.setHostName(HOST);
    bollo_db.setDatabaseName(SCHEMA);
    bollo_db.setUserName(USER);
    bollo_db.setPassword(PASSWORD);

    this->success_connection = bollo_db.open();

}

Person* BolloApp::get_current_user() {
    return &(this->current_user);
}

void BolloApp::set_user(Person* person) {
    this->current_user = *person;
}
