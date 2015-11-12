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
#include <QtCore/qqueue.h>
#include <QtCore/qthread.h>
#include <QtCore/qwaitcondition.h>
#include <QtCore/qmutex.h>

#include "../core/build.h"
#include "easylogging++.h"
#include "../core/classes/logbook.h"

extern QMutex mutex;

class LoggerWorker : public QObject {
Q_OBJECT
private:
    QQueue<Logbook*>* buffer;
public:
    LoggerWorker(QQueue<Logbook*>* buf) :
            buffer(buf) {

    }

    int insert_logbook_entry(QString d, int b) {
        QSqlQuery query;

        query.prepare(
                QStringLiteral("INSERT INTO bollo_logbook "
                                       "VALUES(DEFAULT, :1, NOW() at time zone 'utc-6', :2) "
                                       "RETURNING logbook_id"));

        query.bindValue(":1", QVariant(d));
        query.bindValue(":2", QVariant(b));

        if(query.exec()) {
            if(query.next()) {
                return query.value(0).toInt();
            }
        }
        LOG(ERROR) << "Failed to add a bollo_log entry";
        return 0;

    }

public slots:

    void send_logbook_entries() {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
        while(!buffer->isEmpty()) {
            Logbook* _entry = buffer->dequeue();

            QSqlQuery query;
            QString sql;

            int id = insert_logbook_entry(_entry->getDescription(), _entry->getBakeryId());

            if(id) {
                if(LogbookProblem* p = dynamic_cast<LogbookProblem*>(_entry)) {
//                    LOG(DEBUG) << "Sending new problem logbook entry";
                    query.prepare(QStringLiteral("INSERT INTO bollo_logbook_problem VALUES(:1, :2)"));
                    query.bindValue(":1", QVariant(id));
                    query.bindValue(":2", QVariant(p->get_dough()));

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCDFAInspection"
                } else {//Ignore the stupid CLion warning about unreachable code
//                    LOG(DEBUG) << "Sending new event logbook entry";
                    query.prepare(QStringLiteral("INSERT INTO bollo_logbook_general VALUES(:1)"));
                    query.bindValue(":1", QVariant(id));
                }
#pragma clang diagnostic pop
                delete _entry;
                if(!query.exec()) {
                    LOG(WARNING) << "Failed to execute query -> " << query.lastError().text().toStdString();
                }

            } else {
                LOG(WARNING) << "Failed to add the logbook entry -> " << query.lastError().text().toStdString();
            }
        }
#pragma clang diagnostic pop
    };
};

class Logger : public QObject {
Q_OBJECT
    Logbook* entry;
    LoggerWorker* worker;

    QQueue<Logbook*>* buffer;

    QThread worker_thread;
public:

    Logger() {
        buffer = new QQueue<Logbook*>();
        worker = new LoggerWorker(buffer);
        worker->moveToThread(&worker_thread);

        /* Regular connects */
        connect(&worker_thread, &QThread::finished, worker, &LoggerWorker::deleteLater);
        connect(this, &Logger::start_worker, worker, &LoggerWorker::send_logbook_entries);

        worker_thread.start();
    }

    ~Logger() {
        worker_thread.quit();
        worker_thread.wait();
        delete buffer;
        delete entry;
    }

    Logger& operator<<(const QString&);
    Logger& general(int);
    Logger& problem(int, int);

signals:
    void start_worker();
};

#endif //BOLLO_LOGGER_H
