//
// Created by ricardo on 05/10/15.
//

#ifndef BOLLO_LOGGER_H
#define BOLLO_LOGGER_H

#include <QtNetwork/qnetworkaccessmanager.h>
#include <QtCore/qurl.h>

#include "../io/http.h"
#include "easylogging++.h"

/**
 * Class used to communicate with the API server to notify
 * about a bakery process change.
 *
 * @author Ricardo Madriz
 */
class Logger : public QObject {
Q_OBJECT
public:

    /**
     * Class constructor.
     */
    Logger() { }

    /**
     * Class destructor.
     */
    ~Logger() { }

public slots:
    void send_logbook_entry(int, QString);
    void send_logbook_problem(int, QString, int);
};

#endif //BOLLO_LOGGER_H
