//
// Created by ricardo on 05/10/15.
//

#ifndef BOLLO_LOGGER_H
#define BOLLO_LOGGER_H

//std libs
#include <ctime>

#include <QtCore/qsemaphore.h>
#include <QtCore/qvariant.h>
#include <QDebug>

#include <QtSql/qsqldatabase.h>
#include <QtSql/qsqlerror.h>
#include <QtSql/qsqlquery.h>

#include "../core/build.h"
#include "../io/sql.h"

extern QSemaphore mtx;
extern QSemaphore mtx_writer;

enum LogType {
    DEBUG, WARNING, ERROR
};

class LogBook {
    int bakery_id;
    int dough;
    bool normal;
public:
    LogBook& operator<<(const QString&);
    LogBook& general(int);
    LogBook& problem(int, int);

    int insert_logbook_entry(QString, int);
};

extern LogBook _log;

#endif //BOLLO_LOGGER_H
