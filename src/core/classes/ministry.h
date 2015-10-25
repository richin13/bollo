//
// Created by ricardo on 21/10/15.
//

#ifndef BOLLO_MINISTRY_H
#define BOLLO_MINISTRY_H


#include <QtCore/qthread.h>
#include <QtCore/qvector.h>
#include "bakery.h"
#include "../bollo.h"

class Ministry : QThread {
private:
    QVector<Bakery> bakeries;
    //Bakeries to check
    BolloApp* app;
    virtual void run() override;
public:
    Ministry();
};


#endif //BOLLO_MINISTRY_H
