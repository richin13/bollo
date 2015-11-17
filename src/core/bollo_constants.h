//
// Created by ricardo on 28/10/15.
//

#ifndef BOLLO_BOLLO_CONSTANTS_H
#define BOLLO_BOLLO_CONSTANTS_H

#include <QtCore/qstring.h>

class Constants {
private:
    /**
     * @brief Class constructor
     */
    Constants() { }

    /**
     * @brief Class destructor.
     */
    ~Constants() { }

    /**
     * @brief Copy constructor
     */
    Constants(const Constants&) { }

public:
    /* Networking group */
    /**
     * The host where the API lives.
     */
    static QString API_HOST;

    /**
     * The path of the API inside that host.
     */
    static QString API_PATH;
};

#endif //BOLLO_BOLLO_CONSTANTS_H
