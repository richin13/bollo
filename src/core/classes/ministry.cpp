//
// Created by ricardo on 21/10/15.
//

#include <QtCore/qdatetime.h>
#include "ministry.h"

Ministry::Ministry() { }

void Ministry::run() {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    int chance = 50;//get_setting("Operations", "raid_probability").toInt();

    for(; ;) {//To avoid endless loop warning!
        qsrand((uint) QTime::currentTime().msec());
        unsigned long rnd = qrand() % BolloApp::get().bakeries.size();
        Bakery* b = BolloApp::get().bakeries.at(rnd);

        if(!(b->is_closed_down())) {
            int probability = qrand() % 100 - chance;

            if(probability < 0) {
                b->close_down();

                Quarantine* quarantine = new Quarantine(b);
                QObject::connect(quarantine, SIGNAL(finished()), quarantine, SLOT(deleteLater()));
                quarantine->start();
            }
        }

        QThread::usleep(500000);

    }
#pragma clang diagnostic pop
}

void Quarantine::run() {
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), bakery->get_baker(), SLOT(start_clean()));
    connect(timer, SIGNAL(timeout()), timer, SLOT(deleteLater()));

    /* When the timer finish the clean of the bakery is started */
    timer->start(QUARANTINE_MSECS);
}
