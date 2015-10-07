//
// Created by ricardo on 05/10/15.
//
#include "../core/build.h"
#include "sql.h"

using namespace bollo::_sql;

Driver* BolloConn::driver;
Connection* BolloConn::con;

BolloConn::BolloConn() {

}

BolloConn::~BolloConn() {
    //log this
}

Connection* BolloConn::getConn() {
    if(BolloConn::con == nullptr) {
        driver = get_driver_instance();
        con = driver->connect(HOST, USER, PASSWORD);
        con->setSchema(SCHEMA);//FIXME:define the real schema name
    }

    return con;
}