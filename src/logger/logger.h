//
// Created by ricardo on 05/10/15.
//

#ifndef BOLLO_LOGGER_H
#define BOLLO_LOGGER_H

//std libs
#include <QtCore/qsemaphore.h>
#include "../core/build.h"
#include <QtSql/qsqldatabase.h>
#include <QtSql/qsqlerror.h>
#include "../io/sql.h"
#include <QDebug>

extern QSemaphore mtx;

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
