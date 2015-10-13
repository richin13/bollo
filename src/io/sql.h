//
// Created by ricardo on 05/10/15.
//

#ifndef BOLLO_SQL_H
#define BOLLO_SQL_H

#include <QtSql/qsqldatabase.h>

//std libs
#include "../core/build.h"

namespace bollo {

    namespace query {
        int login(const QString, const QByteArray);
    }
}


#endif //BOLLO_SQL_H
