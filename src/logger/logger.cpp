//
// Created by ricardo on 05/10/15.
//

#include "logger.h"

using namespace bollo::logger;

LogBook bollo::_log;

/**
 * Overloaded function for the '<<' operator.
 * Please use _log.bakery(bakery_id) to add an entry
 * to the logbook.
 */
LogBook &LogBook::operator<<(const string &x) {
    Connection* conn = BolloConn::getConn();
    PreparedStatement* ps = conn->prepareStatement("INSERT INTO "\
    "bollo_logbook(logbook_description, logbook_bakery) VALUES(?, ?)");
    ps->setString(1, x);
    ps->setInt(2, this->bakery_id);

    if(ps->execute()) {
        cout << "Succeded!\n";
    } else {
        //failed!
    }

    return *this;
}

/**
 * Saves an entry into the logbook
 */
LogBook &LogBook::bakery(int bakery_id) {
    unique_lock<mutex> lck(mtx);
    this->bakery_id = bakery_id;
    cv.notify_all();
    return *this;
}