//
// Created by ricardo on 10/11/15.
//

#include "baker.h"


void Baker::run() {
    QThread::wait(5000);//Apparently, it just take 5 secs to clean all the mess.
    Popup* p = new Popup("Limpieza lista", "El panadero ha terminado la limpieza de " + bakery_name);
    p->showPopup();
    QObject::connect(p, SIGNAL(destroyed()), p, SLOT(deleteLater()));

    emit clean_ready();
}

void Baker::find_pollutants(_operation op) {
    if(op.progress / 100 < 3 && !(op.progress % 100)) {

        qsrand((uint) QTime::currentTime().msec());
        int chance = get_setting("Operations", "poll_probability").toInt();
        int dough = get_setting("Operations", "dough_per_batch").toInt();
        int rnd = qrand() % 100 - chance;

        if(rnd < 0) {
            LOG(INFO) << "Found a pollutant in bakery " + to_string(op.bakery_id);
            QString text = "Se encontró " + pollutants.at(qrand() % pollutants.size());
            logbook.problem(op.bakery_id, (qrand() % (dough - 1)) + 1) << text;
            Popup* notification = new Popup("Contaminante", text);
            notification->showPopup();
            QObject::connect(notification, SIGNAL(destroyed()), notification, SLOT(deleteLater()));
        }
    }
}

void Baker::start_clean() {
    this->start();
}