//
// Created by ricardo on 21/10/15.
//

#ifndef BOLLO_MINISTRY_H
#define BOLLO_MINISTRY_H


#include <QtCore/qthread.h>
#include <QtCore/qvector.h>

#include "bakery.h"
#include "../bollo.h"
#include "../operations.h"
#include "../../logger/logger.h"

#define QUARANTINE_SECS 50

class Bakery;

class Ministry : public QThread {
Q_OBJECT
private:
    /**
     * Logger used to send logbook entries to the server.
     */
    Logger* logbook;

    /**
     * Whether the ministry of health is running or not.
     */
    bool stopped;

public:

    /**
     * @brief The class constructor.
     */
    Ministry() {
        logbook = new Logger;
        stopped = false;
        QObject::connect(this, &Ministry::notify_, logbook, &Logger::send_logbook_entry);
    }

    ~Ministry();

    void stop();
protected:
    virtual void run() override;
signals:
    void notify_(int, QString);
};

class Quarantine : public QThread {
Q_OBJECT
private:
    /**
     * A pointer to the bakery in quarantine.
     */
    Bakery* bakery;

    /**
     * Logger used to send logbook entries to the server.
     */
    Logger* logbook;

    /**
     * @brief Class constructor. Private because bakery pointer is necessary.
     */
    Quarantine() { }

public:

    /**
     * @brief Quarantine class constructor.
     * @param _bak Bakery that is entering quarantine.
     */
    Quarantine(Bakery* _bak) : bakery(_bak) {
        logbook = new Logger;
        QObject::connect(this, &Quarantine::notify_, logbook, &Logger::send_logbook_entry);
    }

    /**
     * @brief Class destructor.
     */
    ~Quarantine() {
        delete logbook;
    }

public slots:
    void notify_exit_quarantine();

signals:
    void notify_(int, QString);
    void exiting_quarantine();

protected:
    virtual void run() override;
};

#endif //BOLLO_MINISTRY_H
