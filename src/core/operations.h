//
// Created by ricardo on 10/11/15.
//

#ifndef BOLLO_OPERATIONS_H
#define BOLLO_OPERATIONS_H

#include "../logger/logger.h"

extern Logger logbook;

typedef unsigned short int integer_code;

struct _operation {
    unsigned int bakery_id;
    integer_code progress;
    QString description;
};

#endif //BOLLO_OPERATIONS_H
