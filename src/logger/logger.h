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

#include <pthread.h>//Officially not multiplatform.

#include "../core/build.h"
#include "../io/sql.h"
#include "easylogging++.h"
extern QSemaphore mtx;
extern QSemaphore mtx_writer;

typedef struct {
    QString message;
    int bakery_id;
} th_data;

class LogBook {
    int bakery_id;
    int dough;
    bool normal;

//    QQueue<th_data>
public:
    LogBook& operator<<(const QString&);
    LogBook& general(int);
    LogBook& problem(int, int);

    int insert_logbook_entry(QString, int);
};


void* send_query(void*);

extern LogBook logbook;

#endif //BOLLO_LOGGER_H
