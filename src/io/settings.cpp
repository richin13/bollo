//
// Created by ricardo on 10/11/15.
//

#include "settings.h"

void init_settings(void) {
    LOG(INFO) << "Loading Bollo settings";
    QDir app_dir = QDir(QDir().homePath() + "/bollo");
    QString absolute_path = app_dir.absolutePath();

    if(!app_dir.exists()) {
        QDir().mkdir(absolute_path);
        load_default_settings();
    } else {
        QFileInfo config_file = QFileInfo(config_file_path());
        if(!config_file.exists()) {
            LOG(INFO) << "Settings file not found, creating default...";
            load_default_settings();
            LOG(INFO) << "Settings file created";
        }
    }
    load_settings();
}

void load_default_settings(void) {
    QString fullPath = config_file_path();

    if(QFile::exists(fullPath)) {
        QFile::remove(fullPath);
    }

    QSettings bollo_settings(fullPath, QSettings::NativeFormat);

    /* Networking settings */
    bollo_settings.beginGroup(QStringLiteral("Networking"));
    bollo_settings.setValue(QStringLiteral("host_url"), QVariant("http://bollo-server.bitnamiapp.com/bollo_web"));
    bollo_settings.setValue(QStringLiteral("api_path"), QVariant("/api/v1"));
    bollo_settings.endGroup();

    /* Db settings */
    bollo_settings.beginGroup(QStringLiteral("Database"));
    bollo_settings.setValue(QStringLiteral("db_host"), QVariant("104.154.49.207"));
    bollo_settings.setValue(QStringLiteral("db_user"), QVariant("postgres"));
    bollo_settings.setValue(QStringLiteral("db_pass"), QVariant("W3aS28yt"));
    bollo_settings.setValue(QStringLiteral("db_schema"), QVariant("bollo_testing_final"));
    bollo_settings.endGroup();

    /* General operations settings */
    bollo_settings.beginGroup(QStringLiteral("Operations"));
    bollo_settings.setValue(QStringLiteral("average_production"), QVariant(55));
    bollo_settings.setValue(QStringLiteral("dough_per_batch"), QVariant(15));
    bollo_settings.setValue(QStringLiteral("poll_probability"), QVariant(10));
    bollo_settings.setValue(QStringLiteral("badyeast_probability"), QVariant(10));//Man, this is hard
    bollo_settings.setValue(QStringLiteral("raid_probability"), QVariant(2));
    bollo_settings.endGroup();
}

void load_settings(void) {
    QString cf_path = config_file_path();

    if(!QFile::exists(cf_path)) {
        throw std::exception();
    }

    QSettings bollo_settings(cf_path, QSettings::NativeFormat);

    /* Networking settings */
    bollo_settings.beginGroup(QStringLiteral("Networking"));
    Constants::API_HOST = bollo_settings.value("host_url").toString();
    Constants::API_PATH = bollo_settings.value("api_path").toString();
    bollo_settings.endGroup();

    /* Db settings */
    bollo_settings.beginGroup(QStringLiteral("Database"));
    Constants::DB_HOST = bollo_settings.value("db_host").toString();
    Constants::DB_USERNAME = bollo_settings.value("db_user").toString();
    Constants::DB_PASSWORD = bollo_settings.value("db_pass").toString();
    Constants::DB_SCHEME = bollo_settings.value("db_schema").toString();
    bollo_settings.endGroup();

}

QString config_file_path() {
    QDir app_dir = QDir(QDir().homePath() + "/bollo");
    return QString(app_dir.absolutePath() + "/settings/bollo.ini");
}

void set_setting(const QString& group, const QString& key, const QVariant& value) {
    static QString cf_path = config_file_path();
    static QSettings bollo_settings(cf_path, QSettings::NativeFormat);

    bollo_settings.beginGroup(group);
    bollo_settings.setValue(key, value);
    bollo_settings.endGroup();
}

QVariant get_setting(const QString& group, const QString& key) {
    static QString cf_path = config_file_path();
    static QSettings bollo_settings(cf_path, QSettings::NativeFormat);

    bollo_settings.beginGroup(group);
    QVariant result = bollo_settings.value(key);
    bollo_settings.endGroup();

    return result;
}
