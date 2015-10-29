//
// Created by ricardo on 28/10/15.
//

#ifndef BOLLO_BOLLO_CONSTANTS_H
#define BOLLO_BOLLO_CONSTANTS_H

#include <QtCore/qstring.h>

class Constants {
private:
    Constants() { }

    ~Constants() { }

    Constants(const Constants&) { }

public:
    /* Networking group */
    static QString API_HOST;
    static QString API_PATH;

/* Database group */
    static QString DB_HOST;
    static QString DB_USERNAME;
    static QString DB_PASSWORD;
    static QString DB_SCHEME;
};

#endif //BOLLO_BOLLO_CONSTANTS_H
