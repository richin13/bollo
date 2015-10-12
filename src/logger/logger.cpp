//
// Created by ricardo on 05/10/15.
//

#include <QtSql/qsqlquery.h>
#include <QtCore/qvariant.h>
#include "logger.h"

using namespace bollo::logger;

LogBook bollo::_log;

QSemaphore bollo::logger::mtx;

/**
 * Overloaded function for the '<<' operator.
 * Please use _log.bakery(bakery_id) to add an entry
 * to the logbook.
 * @param x QString Event information.
 */
LogBook &LogBook::operator<<(const QString x) {
    /*
    Connection* conn = BolloConn::getConn();//FIXME: No longer using mysql
    PreparedStatement* ps = conn->prepareStatement("INSERT INTO "\
    "bollo_logbook(logbook_description, logbook_bakery) VALUES(?, ?)");
    ps->setString(1, x);
    ps->setInt(2, this->bakery_id);
    */

    QSqlQuery query;
    query.prepare("INSERT INTO bollo_logbook(logbook_description, "\
                          "logbook_bakery) VALUES(?, ?)");
    query.addBindValue(QVariant(x));
    query.addBindValue(QVariant(this->bakery_id));

    if(!query.exec()) {
        cerr << "Failed to execute\n";
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
LogBook &LogBook::bakery(int bakery_id) {
    mtx.acquire();//One thread at a time
    this->bakery_id = bakery_id;
    return *this;
}