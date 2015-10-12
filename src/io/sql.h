//
// Created by ricardo on 05/10/15.
//

#ifndef BOLLO_SQL_H
#define BOLLO_SQL_H

//mysql-connector-c++ libraries.
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include <QtSql/qsqldatabase.h>

//std libs
#include "../core/build.h"

using namespace sql;
using namespace sql::mysql;

namespace bollo {

    namespace _sql {
        int login(QString, QByteArray);
    }
}


#endif //BOLLO_SQL_H
