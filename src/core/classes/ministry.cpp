//
// Created by ricardo on 21/10/15.
//

#include <QtCore/qdatetime.h>
#include "ministry.h"

Ministry::Ministry() { }

void Ministry::run() {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    for(; ;) {
        int chance = get_setting("Operations", "raid_probability").toInt();
        qsrand((uint) QTime::currentTime().msec());
        unsigned long rnd = qrand() % BolloApp::get().bakeries.size();
        Bakery* b = BolloApp::get().bakeries.at(rnd);

        if(!(b->is_closed_down())) {
            int probability = qrand() % 100 - chance;
            if(probability < 0) {
                b->close_down();

                Quarantine* quarantine = new Quarantine(b);
                QObject::connect(quarantine, SIGNAL(exiting_quarantine()), quarantine, SLOT(deleteLater()));
                quarantine->start();
            }
        }

        QThread::usleep(9500000);
    }
#pragma clang diagnostic pop
}

void Quarantine::run() {
    LOG(DEBUG) << "Entering quarantine [" + to_string(bakery->get_id()) + "]";

    _operation op;
    op.bakery_id = bakery->get_current_op().bakery_id;
    op.stock = bakery->get_current_op().stock;
    op.progress = 1000;
    op.description = "En cuarentena";

    bakery->set_current_op(op);
    emit bakery->operation_changed(bakery->get_current_op());//Watch out fah dis

    logbook.general(bakery->get_id()) << "Entrando en cuarentena";
    QThread::sleep(40);

//    QTimer::singleShot(QUARANTINE_MSECS, bakery->get_baker(), SLOT(start_clean()));
//    QTimer::singleShot(QUARANTINE_MSECS, this, SLOT(notify_exit_quarantine()));
    bakery->get_baker()->start_clean();
    this->notify_exit_quarantine();

}

void Quarantine::notify_exit_quarantine() {
    emit exiting_quarantine();
}
