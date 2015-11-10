//
// Created by ricardo on 11/10/15.
//

#ifndef BOLLO_BOLLO_H
#define BOLLO_BOLLO_H

#define APP_NAME "Bollo"
#define CODENAME "Baguette"
#define VERSION "0.0.2-build-11_1"//[version]-build-{MONTH_week}

#include <QtSql/qsqldatabase.h>

#include <QtCore/qsettings.h>
#include <QtCore/qstandardpaths.h>
#include <QtCore/qdir.h>

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

    void init_updater();

    QString config_file_path() const;
public:
    /* User information */
    Person* current_user;

    /* Database connection information */
    QSqlDatabase bollo_db;

    /* Settings and directories */
    QDir app_dir;//TODO: Find a way to deallocate this!

    /* Application data */
    std::vector<Bakery> bakeries;

    /* Status updater */
    StatusUpdater* updater;

    QString windowTittle();

    static BolloApp& get();

    void set_setting(const QString&, const QString&, const QVariant&);
    QVariant get_setting(const QString&, const QString&);

    const QString& get_bakery_name(int);
public slots:
    void loaded_bakeries(QNetworkReply*);

signals:
    void application_exiting();
};


#endif //BOLLO_BOLLO_H
