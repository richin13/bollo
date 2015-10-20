//
// Created by ricardo on 17/10/15.
//

#include <QtCore/qtimer.h>
#include "baker.h"

void Baker::run() {
    QTimer timer;
    //TODO: should emmit a signal saying clean is ready
}


void Baker::start_clean(int dough) {
    //TODO: Log this!
    this->start();
}
