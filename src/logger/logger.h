//
// Created by ricardo on 05/10/15.
//

#ifndef BOLLO_LOGGER_H
#define BOLLO_LOGGER_H

#include "../io/sql.h"

using namespace bollo::_sql;

namespace logger {

    class LogBook {

    public:
        LogBook &operator<<(const string &);
    };

}

using namespace logger;

extern LogBook _log;

#endif //BOLLO_LOGGER_H
