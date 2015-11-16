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
    Logger* logbook;
    virtual void run() override;
public:
    Ministry() {
        logbook = new Logger;

        QObject::connect(this, &Ministry::notify_, logbook, &Logger::send_logbook_entry);
    }

    ~Ministry();

signals:
    void notify_(int, QString);
};

class Quarantine : public QThread {
Q_OBJECT
private:
    Bakery* bakery;
    Logger* logbook;

    Quarantine() { }

public:
    Quarantine(Bakery* _bak) : bakery(_bak) {
        logbook = new Logger;
        QObject::connect(this, &Quarantine::notify_, logbook, &Logger::send_logbook_entry);
    }

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
