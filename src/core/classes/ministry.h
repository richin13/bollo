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

#define QUARANTINE_MSECS 12000

class Bakery;

class Ministry : public QThread {
private:
    virtual void run() override;
public:
    Ministry();
};

class Quarantine : public QThread {
Q_OBJECT
private:
    Bakery* bakery;

    Quarantine() { }

public:
    Quarantine(Bakery* _bak) : bakery(_bak) {

    }

public slots:
    void notify_exit_quarantine();

signals:
    void exiting_quarantine();

protected:
    virtual void run() override;
};

#endif //BOLLO_MINISTRY_H
