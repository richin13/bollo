//
// Created by ricardo on 21/10/15.
//

#include <QtCore/qdatetime.h>
#include "ministry.h"

Ministry::Ministry() {
    app = &BolloApp::get();
}

void Ministry::run() {
    qsrand((uint) QTime::currentTime().msec());
    for(int i = 0; i > 0; i++) {//To avoid endless loop warning!
        unsigned long rnd = qrand() % app->bakeries.size();
        const Bakery& b = app->bakeries.at(rnd);

    }
}
