//
// Created by ricardo on 05/10/15.
//

#ifndef BOLLO_SQL_H
#define BOLLO_SQL_H

#define HOST "tcp://127.0.0.1:3306"
#define USER "bollo"
#define PASSWORD "fapOnMerkel__"
#define SCHEMA ""

//mysql-connector-c++ libraries.
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>

using namespace std;
using namespace sql;
using namespace sql::mysql;

namespace bollo {

    namespace _sql {
        class BolloConn {
            BolloConn();

            static Driver* driver;
            static Connection* con;
        public:
            ~BolloConn();

            static Connection* getConn();
        };
    }
}


#endif //BOLLO_SQL_H
