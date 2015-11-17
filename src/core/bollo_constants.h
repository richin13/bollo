//
// Created by ricardo on 28/10/15.
//

#ifndef BOLLO_BOLLO_CONSTANTS_H
#define BOLLO_BOLLO_CONSTANTS_H

#include <QtCore/qstring.h>

/**
 * Class that contains all the constants of the application.
 * Those constants are widely available through all the code
 * and are not actually 'constants' as defined in C++ programming
 * language, but constants for the application execution.
 *
 * @author Ricardo Madriz
 */
class Constants {
private:
    /**
     * Class constructor
     */
    Constants() { }

    /**
     * Class destructor.
     */
    ~Constants() { }

    /**
     * Copy constructor
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

    /**
     * Super secret server backdoor to access charts.
     */
    static QString CHARTS_URL;
};

#endif //BOLLO_BOLLO_CONSTANTS_H
