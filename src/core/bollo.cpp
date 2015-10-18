//
// Created by ricardo on 11/10/15.
//


#include "bollo.h"

/***************************************/
/*        Definitions                 */
/**************************************/
QString BolloApp::app_name;
QString BolloApp::codename;
QString BolloApp::version;

Person* BolloApp::current_user;

bool BolloApp::success_connection;

QVector<Bakery> BolloApp::bakeries;//TODO: Load'em from db

BolloApp::BolloApp(int argc, char** argv) : QApplication(argc, argv) {
    BolloApp::app_name = "Bollo";
    BolloApp::codename = "Ajonjoli";
    BolloApp::version = "0.0.1-build-10_1";//[version]-build-{MONTH_week}

    this->app_dir = new QDir(QDir().homePath() + "/bollo");

    /* The database connection - Only need to be done once */
    init_database();

}


void BolloApp::init_database(void) {
    this->bollo_db = QSqlDatabase::addDatabase("QPSQL");
    bollo_db.setHostName(HOST);
    bollo_db.setDatabaseName(SCHEMA);
    bollo_db.setUserName(USER);
    bollo_db.setPassword(PASSWORD);

    BolloApp::success_connection = bollo_db.open();
}

void BolloApp::init_settings(void) {
    QString absolutePath = this->app_dir->absolutePath();

    if(!this->app_dir->exists()) {
        QDir().mkdir(absolutePath);
        load_default_settings();
    } else {
        QFileInfo config_file = QFileInfo(absolutePath + "/settings/bollo.ini");
        if(!config_file.exists()) {
            load_default_settings();
        } else {
            QSettings init_settings(config_file.absoluteFilePath(), QSettings::NativeFormat);
        }
    }
}

void BolloApp::load_default_settings(void) {
    QString fullPath = this->app_dir->absolutePath() + "/settings/bollo.ini";

    if(QFile::exists(fullPath)) {
        QFile::remove(fullPath);
    }

    QFileInfo config_file = QFileInfo(fullPath);
    QSettings bollo_settings(config_file.absoluteFilePath(), QSettings::NativeFormat);

    /* Networking settings */
    bollo_settings.beginGroup("Networking");
    bollo_settings.setValue("host_url", QVariant(WEB_HOST));
    bollo_settings.setValue("api_path", QVariant(API_PATH));
    bollo_settings.setValue("api_token", QVariant(API_TOKEN));
    bollo_settings.endGroup();
}

QString BolloApp::windowTittle() {
    return QString("%1-[%2]_%3").arg(BolloApp::app_name, BolloApp::codename, BolloApp::version);
}