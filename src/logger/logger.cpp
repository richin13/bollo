//
// Created by ricardo on 05/10/15.
//

#include "logger.h"

LogBook &LogBook::operator<<(const string &x) {
    Connection* conn = BolloConn::getConn();
    PreparedStatement* ps = conn->prepareStatement("INSERT INTO bollo_logbook(bollo_description) VALUES(?)");
    ps->setString(1, x);
    return *this;
}