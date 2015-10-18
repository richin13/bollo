//
// Created by ricardo on 11/10/15.
//

#ifndef BOLLO_BOLLO_H
#define BOLLO_BOLLO_H
#define WEB_HOST "localhost/bollo_web"
#define API_PATH "localhost/bollo_web/api/v1/"
#define API_TOKEN "db759b5699aad48f"
#define HOST "104.154.49.207"
#define USER "postgres"
#define PASSWORD "W3aS28yt"
#define SCHEMA "bollo_test"

#include <QtWidgets/qapplication.h>
#include <QtSql/qsqldatabase.h>
#include <QtCore/qsettings.h>
#include <QtCore/qstandardpaths.h>
#include <QtCore/qdir.h>
#include <QtCore/qvector.h>


#include "build.h"
#include "classes/person.h"
#include "classes/bakery.h"

class BolloApp : public QApplication {
private:
    void init_database(void);

    void init_settings(void);

    void load_default_settings(void);

public:
    /* Basic application information */
    static QString app_name;
    static QString codename;
    static QString version;

    /* User information */
    static Person* current_user;

    /* Database connection information */
    QSqlDatabase bollo_db;
    //No need to be static
    static bool success_connection;

    /* Settings and directories */
    QDir* app_dir;

    /* Application data */
    static QVector<Bakery> bakeries;

    /* Constructors */
    explicit BolloApp(int argc, char** argv);

    static QString windowTittle();
};


#endif //BOLLO_BOLLO_H
