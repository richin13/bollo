//
// Created by ricardo on 05/10/15.
//

#ifndef BOLLO_LOGGER_H
#define BOLLO_LOGGER_H

//std libs
#include <QtCore/qsemaphore.h>
#include "../core/build.h"

#include "../io/sql.h"

using namespace bollo::_sql;

namespace bollo {
    namespace logger {
        extern QSemaphore mtx;
        class LogBook {
            int bakery_id;
        public:
            LogBook &operator<<(const QString);
            LogBook &bakery(int);
        };

    }

    extern logger::LogBook _log;
}

#endif //BOLLO_LOGGER_H
