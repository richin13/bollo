//
// Created by ricardo on 11/10/15.
//

#ifndef BOLLO_BOLLO_H
#define BOLLO_BOLLO_H

#define APP_NAME "Bollo"
#define CODENAME "Ajonjoli"
#define VERSION "0.0.1-build-10_4"//[version]-build-{MONTH_week}

#include <QtSql/qsqldatabase.h>
#include <QtCore/qsettings.h>
#include <QtCore/qstandardpaths.h>
#include <QtCore/qdir.h>
#include <QtCore/qvector.h>
#include <QtNetwork/qnetworkreply.h>

#include "build.h"
#include "classes/person.h"
#include "classes/bakery.h"
#include "bollo_constants.h"

class BolloApp : public QObject {
Q_OBJECT
private:
    BolloApp();

    ~BolloApp();

    BolloApp(const BolloApp&) { }

    void operator=(BolloApp const&) { }


    void init_database(void);

    void init_settings(void);

    void load_default_settings(void);

    void load_settings(void);

    void load_bakeries_from_db();


    QString config_file_path() const;
public:
/* User information */
    Person* current_user;

    /* Networking connection manager */
    QNetworkAccessManager* manager;

    /* Database connection information */
    QSqlDatabase bollo_db;

    /* Settings and directories */
    QDir* app_dir;//TODO: Find a way to deallocate this!

    /* Application data */
    std::vector<Bakery> bakeries;

    QString windowTittle();

    static BolloApp& get();

    void set_setting(const QString&, const QString&, const QVariant&);
    QVariant get_setting(const QString&, const QString&);
public slots:
    void loaded_bakeries(QNetworkReply*);
};


#endif //BOLLO_BOLLO_H
