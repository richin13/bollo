//
// Created by ricardo on 05/10/15.
//

#include "logger.h"

using namespace bollo::logger;

LogBook bollo::_log;

LogBook &LogBook::operator<<(const string &x) {
    Connection* conn = BolloConn::getConn();
    PreparedStatement* ps = conn->prepareStatement("INSERT INTO "\
    "bollo_logbook(logbook_description, logbook_bakery) VALUES(?, ?)");
    ps->setString(1, x);
    ps->setInt(2, 1);

    if(ps->execute()) {
        cout << "Succeded!\n";
    } else {
        //failed!
    }

    return *this;
}