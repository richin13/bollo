//
// Created by ricardo on 11/10/15.
//

#ifndef BOLLO_BOLLO_H
#define BOLLO_BOLLO_H

#define WEB_HOST "http://localhost/bollo_web"
#define API_PATH "/api/v1"

#define HOST "104.154.49.207"
#define USER "postgres"
#define PASSWORD "W3aS28yt"
#define SCHEMA "bollo_test"

#define APP_NAME "Bollo"
#define CODENAME "Ajonjoli"
#define VERSION "0.0.1-build-10_4"//[version]-build-{MONTH_week}

#include <QtSql/qsqldatabase.h>
#include <QtCore/qsettings.h>
#include <QtCore/qstandardpaths.h>
#include <QtCore/qdir.h>
#include <QtCore/qvector.h>

#include "build.h"
#include "classes/person.h"
#include "classes/bakery.h"

class BolloApp {
private:
    BolloApp();

    BolloApp(const BolloApp&) { }

    void operator=(BolloApp const&) { }
    void init_database(void);

    void init_settings(void);

    void load_default_settings(void);
public:
    /* User information */
    Person* current_user;

    /* Database connection information */
    QSqlDatabase bollo_db;

    /* Settings and directories */
    QDir* app_dir;//TODO: Find a way to deallocate this!

    /* Application data */
    QVector<Bakery> bakeries;

    QString windowTittle();

    static BolloApp& get();
};


#endif //BOLLO_BOLLO_H
