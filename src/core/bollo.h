//
// Created by ricardo on 11/10/15.
//

#ifndef BOLLO_BOLLO_H
#define BOLLO_BOLLO_H

#define APP_NAME "Bollo"
#define CODENAME "Baguette"
#define VERSION "0.0.2-build-11_3"//[version]-build-{MONTH_week}

#include <QtWidgets/qapplication.h>

#include <QtSql/qsqldatabase.h>

#include <QtNetwork/qnetworkreply.h>

#include <QtWidgets/qmessagebox.h>
#include <QtNetwork/qnetworkaccessmanager.h>
#include <QtCore/qjsondocument.h>
#include <QtCore/qjsonarray.h>

#include "build.h"
#include "classes/person.h"
#include "classes/bakery.h"
#include "bollo_constants.h"

#include "../io/http.h"
#include "../io/handler.h"
#include "../io/settings.h"
#include "classes/ministry.h"

class StatusUpdater;

class Bakery;

class Ministry;

class BolloApp : public QObject {
Q_OBJECT
private:
    BolloApp();

    ~BolloApp();

    BolloApp(const BolloApp&) { }

    void operator=(BolloApp const&) { }

    void init_database(void);

    void load_bakeries_from_db();

    void start_bakeries();

    void init_ministry();

    void init_updater();

public:
    /* User information */
    Person* current_user;

    /* Database connection information */
    QSqlDatabase bollo_db;

    /* Application data */
    std::vector<Bakery*> bakeries;

    /* Status updater */
    StatusUpdater* updater;

    /* Ministry of health */
    Ministry* ministry;

    QString windowTittle();

    static BolloApp& get();

    const QString& get_bakery_name(int);
public slots:
    void loaded_bakeries(QNetworkReply*);

signals:
    void start_bakeries_execution();
    void application_exiting();
};

#endif //BOLLO_BOLLO_H
