//
// Created by ricardo on 05/10/15.
//


#include "logger.h"


LogBook _log;

QSemaphore mtx(1);
QSemaphore mtx_logger(1);
QSemaphore mtx_writer(1);

/**
 * Overloaded function for the '<<' operator.
 * Please use _log.bakery(bakery_id) to add an entry
 * to the logbook.
 * @param x QString Event information.
 */
LogBook& LogBook::operator<<(const QString& x) {
    QSqlQuery query;
    QString sql;

    int id = insert_logbook_entry(x, bakery_id);

    if(id) {
        if(normal) {
            query.prepare(QStringLiteral("INSERT INTO bollo_logbook_general VALUES(:1)"));
            query.bindValue(":1", QVariant(id));
        } else {
            query.prepare(QStringLiteral("INSERT INTO bollo_logbook_problem VALUES(:1, :2)"));
            query.bindValue(":1", QVariant(id));
            query.bindValue(":2", QVariant(dough));
        }

        if(!query.exec()) {
            qDebug() << query.lastError();
            cerr << "Failed to execute\n";//TODO: Real logging.
        }

    } else {
        //TODO: Add real loggin here
        qDebug() << "Couldn't add the record!";
        qDebug() << query.lastError();
    }


    mtx.release();
    return *this;
}

/**
 * Saves an entry into the logbook associated to the specified
 * bakery.
 *
 * @param bakery_id int Bakery id.
 */
LogBook& LogBook::general(int bakery_id) {
    mtx.acquire();//One thread at a time
    this->bakery_id = bakery_id;
    this->normal = true;
    return *this;
}

/**
 * Saves an entry into the logbook associated to the specified
 * bakery.
 *
 * @param bakery_id int Bakery id.
 */
LogBook& LogBook::problem(int bakery_id, int dough) {
    mtx.acquire();//One thread at a time
    this->bakery_id = bakery_id;
    this->dough = dough;
    this->normal = false;
    return *this;
}


int LogBook::insert_logbook_entry(QString d, int b) {
    QSqlQuery query;

    query.prepare(QStringLiteral("INSERT INTO bollo_logbook " \
                  "VALUES(DEFAULT, ?, DEFAULT, ?) RETURNING logbook_id"));

    query.addBindValue(QVariant(d));
    query.addBindValue(QVariant(b));

    if(query.exec()) {
        if(query.next()) {
            return query.value(0).toInt();
        }
    }
    //if it reaches here there were a problem.
    return 0;

}