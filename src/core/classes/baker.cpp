//
// Created by ricardo on 10/11/15.
//

#include "baker.h"

Baker::Baker() {
    pollutants.append("Levadura mala");
    pollutants.append("Bacterias");
    pollutants.append("Coliformes");
    pollutants.append("Otros contaminantes");
}

void Baker::run() {
    QTimer timer;
    //TODO: should emmit a signal saying clean is ready
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

void Baker::start_clean(int dough) {
    //TODO: Log this!
    this->start();
}