//
// Created by ricardo on 05/10/15.
//
#include "../core/build.h"
#include "sql.h"

#include <openssl/sha.h>
#include <sstream>

using namespace bollo::_sql;

Driver* BolloConn::driver;
Connection* BolloConn::con;

BolloConn::BolloConn() {

}

BolloConn::~BolloConn() {
    //log this
    delete driver;
    delete con;
}

Connection* BolloConn::getConn() {
    if(BolloConn::con == nullptr) {
        driver = get_driver_instance();
        con = driver->connect(HOST, USER, PASSWORD);
        con->setSchema(SCHEMA);
    }

    return con;
}

bool bollo::_sql::login(string username, string password) {
    string hash = _sha1(password);

    Connection* conn = BolloConn::getConn();
    PreparedStatement* ps = conn->prepareStatement("SELECT user_username, " \
    "user_username WHERE user_username = ? AND user_password = ?");

    ps->setString(1, username);
    ps->setString(2, hash);

    ResultSet* resultSet = ps->executeQuery();

//    if(resultSet->next()) {
//        TODO:log the login attempt succeeded
//        return true;
//    } else {
//        TODO:log the login attempt fail
//        return false;
//    }

    return resultSet->next();

}

string bollo::_sql::_sha1(string password) {
    unsigned char sha_digest[20];

    SHA1((unsigned char*)password.c_str(), password.size(), sha_digest);

    stringstream hashed_pw;
    for(int i = 0; i < 20; ++i) {
        hashed_pw << hex << (int)sha_digest[i];
    }

    return hashed_pw.str();
}