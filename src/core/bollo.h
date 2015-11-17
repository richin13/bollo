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

    void load_bakeries();

    void start_bakeries();

    void init_ministry();

    void init_updater();

public:
    /* User information */
    /**
     * The logged in user.
     */
    Person* current_user;

    /* Application data */
    /**
     * A vector that holds all the bakeries being managed with Bollo.
     */
    std::vector<Bakery*> bakeries;

    /* Status updater */
    /**
     * The bakery status updater.
     */
    StatusUpdater* updater;

    /* Ministry of health */
    /**
     * 'Ministry of health' thread.
     */
    Ministry* ministry;

    static BolloApp& get();

    const QString& get_bakery_name(int);
public slots:
    void loaded_bakeries(QNetworkReply*);
};

#endif //BOLLO_BOLLO_H
