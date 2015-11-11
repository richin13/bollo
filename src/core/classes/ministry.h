//
// Created by ricardo on 21/10/15.
//

#ifndef BOLLO_MINISTRY_H
#define BOLLO_MINISTRY_H


#include <QtCore/qthread.h>
#include <QtCore/qvector.h>
#include "bakery.h"
#include "../bollo.h"

class Ministry : public QThread {
private:
    virtual void run() override;
public:
    Ministry();
};

class Quarantine : public QThread {
#define QUARANTINE_MSECS 120000
private:
    Bakery* bakery;

    Quarantine() { }

public:
    Quarantine(Bakery* _bak) : bakery(_bak) {
        logbook.general(bakery->get_id()) << "Entrando en cuarentena";
    }

protected:
    virtual void run() override;
};

#endif //BOLLO_MINISTRY_H
