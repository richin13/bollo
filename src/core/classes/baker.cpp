//
// Created by ricardo on 10/11/15.
//

#include "baker.h"

/**
 * Runs the baker to perform a cleaning after a bakery leaves quarantine.
 */
void Baker::run() {
    QThread::sleep(10);

    sendInfoNotification("Liempieza lista!", "El panadero ha terminado la limpieza de " + bakery_name.toStdString());

    emit clean_ready();
    LOG(DEBUG) << "Finished clean";
}

/**
 * Activate the baker in order to find any pollutant in the bakery.
 * @param op Struct that contains the bakery's operation information.
 */
void Baker::find_pollutants(_operation op) {
    if(op.progress / 100 < 3 && !(op.progress % 100)) {

        qsrand((uint) QTime::currentTime().msec());
        int chance = get_setting("Operations", "poll_probability").toInt();
        int dough = get_setting("Operations", "dough_per_batch").toInt();
        int rnd = qrand() % 100 - chance;

        if(rnd < 0) {
            LOG(INFO) << "Found a pollutant in bakery " + to_string(op.bakery_id);
            QString text = "Se encontró " + pollutants.at(qrand() % pollutants.size());

            emit found_pollutants(op.bakery_id, text, (qrand() % (dough - 1)) + 1);
            sendInfoNotification(bakery_name.toStdString(), text.toStdString());
        }
    }
}

/**
 * Starts the bakery cleaning
 */
void Baker::start_clean() {
    LOG(DEBUG) << "Starting to clean bakery";
    this->start();
}