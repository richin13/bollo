//
// Created by ricardo on 10/11/15.
//

#include "settings.h"

/**
 * Method used to retrieve the basic Bollo configuration stored
 * in a file at user's home. In case that such file does not exists, it
 * will create a new one.
 */
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

/**
 * Method used to generated a default settings file when
 * a previous one is not found in the user's home directory.
 */
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

    /* General operations settings */
    bollo_settings.beginGroup(QStringLiteral("Operations"));
    bollo_settings.setValue(QStringLiteral("average_production"), QVariant(55));
    bollo_settings.setValue(QStringLiteral("dough_per_batch"), QVariant(15));
    bollo_settings.setValue(QStringLiteral("poll_probability"), QVariant(10));
    bollo_settings.setValue(QStringLiteral("badyeast_probability"), QVariant(10));//Man, this is hard
    bollo_settings.setValue(QStringLiteral("raid_probability"), QVariant(2));
    bollo_settings.endGroup();
}

/**
 * Method used to load the stored settings of the app.
 */
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
}

/**
 * Method the returns the absolute path of settings folder at
 * user's home directory.
 * @return A string with the absolute path to settings folder.
 */
QString config_file_path() {
    QDir app_dir = QDir(QDir().homePath() + "/bollo");
    return QString(app_dir.absolutePath() + "/settings/bollo.ini");
}

/**
 * Sets a new configuration at the specified group. See QSettings API
 *  documentation for details about 'groups'.
 * @group The setting group.
 * @key The key of the setting.
 * @value The value of the setting.
 */
void set_setting(const QString& group, const QString& key, const QVariant& value) {
    static QString cf_path = config_file_path();
    static QSettings bollo_settings(cf_path, QSettings::NativeFormat);

    bollo_settings.beginGroup(group);
    bollo_settings.setValue(key, value);
    bollo_settings.endGroup();
}

/**
 * Retrieves the value of a specific setting at a specific group.
 *  See QSettings API documentation for details about 'groups'
 * @param group The setting group.
 * @param key The key of the setting.
 */
QVariant get_setting(const QString& group, const QString& key) {
    static QString cf_path = config_file_path();
    static QSettings bollo_settings(cf_path, QSettings::NativeFormat);

    bollo_settings.beginGroup(group);
    QVariant result = bollo_settings.value(key);
    bollo_settings.endGroup();

    return result;
}
