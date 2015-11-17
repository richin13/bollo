//
// Created by ricardo on 05/10/15.
//

#include "bakery.h"

/**
 * @brief Copy constructor of class Bakery
 * @param cpy Another bakery instance.
 */
Bakery::Bakery(const Bakery& cpy) {
    bakery_id = cpy.get_id();
    bakery_name = cpy.get_name();
    bakery_state = cpy.get_state();
    bakery_city = cpy.get_city();
    bakery_stock = cpy.get_stock();

    current_operation = cpy.get_current_op();
    stopped = cpy.is_closed_down();
    baker = cpy.get_baker();
}

/**
 * @brief Class destructor
 */
Bakery::~Bakery() {
    delete baker;
    delete yeast;
    delete updater;
    delete logbook;
}

/**
 * @brief Gets the bakery id.
 * @return The bakery id.
 */
unsigned int Bakery::get_id() const {
    return this->bakery_id;
}

/**
 * @brief Gets the bakery name.
 * @return The bakery name
 */
const QString& Bakery::get_name() const {
    return bakery_name;
}

/**
 * @brief Gets the bakery state.
 * @return The bakery state
 */
QString Bakery::get_state() const {
    return bakery_state;
}

/**
 * @brief Gets the bakery city.
 * @return The bakery city
 */
QString Bakery::get_city() const {
    return bakery_city;
}

/**
 * @brief Gets the bakery stock.
 * @return The bakery stock
 */
int Bakery::get_stock() const {
    return this->bakery_stock;
}

/**
 * @brief Stops the execution of bakery thread.
 */
void Bakery::stop() {
    stopped = true;
}

/**
 * @brief Gets the bakery's current operation struct.
 * @return The bakery's current operation struct.
 */
const _operation& Bakery::get_current_op() const {
    return current_operation;
}

/**
 * @brief Sets a new bakery current operation.
 * @param operation Struct with the new operation information.
 */
void Bakery::set_current_op(const _operation& operation) {
    this->current_operation = operation;
}

/**
 * @brief Checks wheter the bakery is closed down or not.
 * @return true if the bakery is closed down, false otherwise.
 */
bool Bakery::is_closed_down() const {
    return stopped;
}

/**
 * @brief Gets the bakery's baker.
 * @return A baker pointer.
 */
Baker* Bakery::get_baker() const {
    return baker;
}

/**
 * @brief The first stage of bread production.
 * @param _start If specified, the process is started at _start value
 * in order the retrieve a previuos status of the bakery.
 */
void Bakery::mix_ingredients(int _start) {
    if(!stopped) {
        qsrand((uint) QTime::currentTime().msec());

        this->current_operation.progress = (integer_code) _start;
        this->current_operation.description = "Mezclando los ingredientes";
        if(!_start)
                emit notify_(bakery_id, current_operation.description);

        int seconds = 20 + (qrand() % 10);

        for(int i = _start; i < 100; ++i) {
            emit internal_oc();
            this->current_operation.progress += 1;
            QThread::usleep((unsigned long) (seconds * LAPSE_TIME));
        }
    }
}

/**
 * @brief Second stage of bakery production.
 * @param _start If specified, the process is started at _start value
 *  in order the retrieve a previuos status of the bakery.
 * @param _final_f If specified, it will perform the final
 *  fermentation of the dough that corresponds to the fifth stage
 *  of bakery production.
 */
void Bakery::ferment_dough(int _start, bool _final_f) {
    if(!stopped) {
        qsrand((uint) QTime::currentTime().msec());

        int seconds;
        if(!_final_f) {
            this->current_operation.description = "Fermentación inicial de la masa";
            seconds = 15 + (qrand() % 10);
        } else {
            this->current_operation.description = "Fermentación final de la masa";
            seconds = 20 + (qrand() % 10);
        }

        if(!_start)
                emit notify_(bakery_id, current_operation.description);

        for(int i = _start; i < 100 && !stopped; ++i) {
            emit internal_oc();
            this->current_operation.progress += 1;
            QThread::usleep((unsigned long) (seconds * LAPSE_TIME));
        }
    }
}

/**
 * @brief Third stage of bakery production.
 * @param _start If specified, the process is started at _start value
 * in order the retrieve a previuos status of the bakery.
 */
void Bakery::divide_dough(int _start) {
    if(!stopped) {
        qsrand((uint) QTime::currentTime().msec());

        this->current_operation.description = "Dividiendo la masa";
        if(!_start)
                emit notify_(bakery_id, current_operation.description);

        int seconds = 15 + (qrand() % 10);

        for(int i = _start; i < 100 && !stopped; ++i) {
            emit internal_oc();
            this->current_operation.progress += 1;
            QThread::usleep((unsigned long) (seconds * LAPSE_TIME));
        }
    }
}

/**
 * @brief The forth stage of bread production.
 * @param _start If specified, the process is started at _start value
 * in order the retrieve a previuos status of the bakery.
 */
void Bakery::shape_dough(int _start) {
    if(!stopped) {
        qsrand((uint) QTime::currentTime().msec());

        this->current_operation.description = "Formando la masa";
        if(!_start)
                emit notify_(bakery_id, current_operation.description);

        int seconds = 30 + (qrand() % 10);

        for(int i = _start; i < 100 && !stopped; ++i) {
            emit internal_oc();
            this->current_operation.progress += 1;
            QThread::usleep((unsigned long) (seconds * LAPSE_TIME));
        }
    }
}

/**
 * @brief The sixth stage of bread production.
 * @param _start If specified, the process is started at _start value
 * in order the retrieve a previuos status of the bakery.
 */
void Bakery::bake_bread(int _start) {
    if(!stopped) {
        qsrand((uint) QTime::currentTime().msec());

        this->current_operation.description = "Horneando el pan";
        if(!_start)
                emit notify_(bakery_id, current_operation.description);

        int seconds = 35 + (qrand() % 10);

        for(int i = _start; i < 100 && !stopped; ++i) {
            emit internal_oc();
            this->current_operation.progress += 1;
            QThread::usleep((unsigned long) (seconds * LAPSE_TIME));
        }

        int dough = get_setting("Operations", "dough_per_batch").toInt();
        bakery_stock = ((dough - (dough / 4)) + (qrand() % 30)) * 5;
        current_operation.stock = bakery_stock;
        LOG(INFO) << "New stock for bakery {" + to_string(bakery_id) + "}: " + to_string(bakery_stock);
        emit updated_stock(bakery_id, bakery_stock);
    }
}

/**
 * @brief The seventh stage of bread production.
 * @param _start If specified, the process is started at _start value
 * in order the retrieve a previuos status of the bakery.
 */
void Bakery::sell_bread(int _start) {
    if(!stopped) {
        qsrand((uint) QTime::currentTime().msec());

        this->current_operation.description = "Vendiendo el pan";
        if(!_start)
                emit notify_(bakery_id, current_operation.description);

        int seconds = 30 + (qrand() % 10);

        for(int i = _start; i < 100 && !stopped; ++i) {
            emit internal_oc();
            this->current_operation.progress += 1;

            if(bakery_stock - 1 > 0 && qrand() % 2) {
                bakery_stock += (qrand() % 2) - 1;
                current_operation.stock = bakery_stock;
            }

            QThread::usleep((unsigned long) (seconds * LAPSE_TIME));
        }
    }
}

/**
 * @brief The eighth stage of bread production.
 * @param _start If specified, the process is started at _start value
 * in order the retrieve a previuos status of the bakery.
 */
void Bakery::distribute_bread(int _start) {
    if(!stopped) {
        qsrand((uint) QTime::currentTime().msec());

        this->current_operation.description = "Distribuyendo el pan";
        if(!_start)
                emit notify_(bakery_id, current_operation.description);

        int seconds = 20 + (qrand() % 10);

        for(int i = _start; i < 100 && !stopped; ++i) {
            emit internal_oc();
            this->current_operation.progress += 1;

            if(bakery_stock - 1 > 0 && qrand() % 2) {
                bakery_stock += (qrand() % 2) - 1;
                current_operation.stock = bakery_stock;
            }

            QThread::usleep((unsigned long) (seconds * LAPSE_TIME));
        }
    }
}

/**
 * @brief Use to stop the bread production at the bakery.
 * @param forever Set this parameter to true to delete the whole process. False
 * to pause it.
 */
void Bakery::stop_operations(bool f) {
    stopped = true;
    this->terminate();
    this->wait();

    string msg = "Se ha pausado ";

    if(f) {
        current_operation.progress = 1100;
        current_operation.description = "Cerrada";
        msg = "Se ha detenido ";
        emit operation_changed(current_operation);
        emit notify_(bakery_id, "Cierre de la panadería");
    }

    showInfoPopup("Panadería detenida", msg + "la producción de pan en " + bakery_name.toStdString());
    LOG(DEBUG) << "Bakery [" + to_string(bakery_id) + "] stopped";
}

/**
 * @brief Resume the bread production at the bakery.
 */
void Bakery::resume_operations(void) {
    if(stopped) {
        stopped = false;

        if(current_operation.progress / 100 == 11 || current_operation.progress / 100 == 8) {
            current_operation.progress = 0;
        }

        this->start();
        LOG(DEBUG) << "Bakery [" + to_string(bakery_id) + "] started";
    } else {
        showInfoPopup(bakery_name.toStdString(), "La panadería ya se encuentra corriendo");
    }
}

/**
 * @brief Slot called when 'Bad yeast' thread attacks!
 */
void Bakery::bad_yeast(void) {
    stopped = true;
    this->terminate();
    this->wait();

    emit notify_(bakery_id, "Intervención del hilo 'Levadura mala'");

    LOG(DEBUG) << "Bakery [" + to_string(bakery_id) + "] affected by bad yeast";

    showWarningPopup("Levadura mala", bakery_name.toStdString() + " ha sido afectada por levadura mala");

    current_operation.progress = 0;

    stopped = false;
    this->start();
}

/**
 * @brief Method called by the Ministry of Health when it
 *  detects a sanity problem in a bakery.
 */
void Bakery::close_down(void) {
    stopped = true;
    this->terminate();
    this->wait();

    current_operation.progress = 900;
    current_operation.description = "Clausarada por el ministerio de salud";
    emit operation_changed(current_operation);

    LOG(DEBUG) << "Bakery [" + to_string(bakery_id) + "] being closed down";

    showWarningPopup("Panadería clausarada",
                     bakery_name.toStdString() + " ha sido clausurada por el ministerio de salud");
}

/**
 * @brief Method called by the Baker in order to make the bakery
 * functional one more time after a close down.
 */
void Bakery::set_up(void) {
    stopped = false;

    /* The operation start from the beggining */
    current_operation.progress = 0;

    LOG(DEBUG) << "Bakery [" + to_string(bakery_id) + "] being set up";
    emit internal_oc();
    showInfoPopup("Panadería lista", bakery_name.toStdString() + " ha salido de cuarentena.");

    this->start();
}

/**
 * @brief Slot that select whether a 'status_changed' notification
 * must be send to the server or not. It is specially useful to
 * avoid the operation_changed signal being overloaded hence other
 * application components do not get its correspondent buffers full
 * of signals.
 */
void Bakery::select_notification() {
//    static int have_not_sent_since = 0;
//    qsrand((uint) QTime::currentTime().msec());

//    if(((qrand() % 8) - 5) > 0 || have_not_sent_since > 5) {
//    if(1) {
    //then send it
    emit operation_changed(current_operation);
//        have_not_sent_since = 0;
//    } else {
//        have_not_sent_since++;
//    }
}

/**
 * @brief The run of the Bakery thread.
 */
void Bakery::run() {
    bool first_time = true;
    while(!stopped) {
        if(first_time) {
            first_time = false;
            switch(current_operation.progress / 100) {
                case 0:
                    mix_ingredients(current_operation.progress % 100);
                case 1:
                    ferment_dough(current_operation.progress % 100);
                case 2:
                    divide_dough(current_operation.progress % 100);
                case 3:
                    shape_dough(current_operation.progress % 100);
                case 4:
                    ferment_dough(current_operation.progress % 100, true);
                case 5:
                    bake_bread(current_operation.progress % 100);
                case 6:
                    sell_bread(current_operation.progress % 100);
                case 7:
                    distribute_bread(current_operation.progress % 100);
                    break;
                case 8:
                case 11:
                    stopped = true;
                    emit operation_changed(current_operation);
                    break;
                case 9:
                case 10: {
                    stopped = true;
                    Quarantine* quarantine = new Quarantine(this);
                    QObject::connect(quarantine, SIGNAL(exiting_quarantine()), quarantine, SLOT(deleteLater()));
                    quarantine->start();
                    break;
                }
                default:
                    LOG(WARNING) << "Other than options established above would be unnexpected at this point";
            }
        } else {
            mix_ingredients();

            ferment_dough();

            divide_dough();

            shape_dough();

            ferment_dough(0, true);

            bake_bread();

            sell_bread();

            distribute_bread();
        }
    }
}
