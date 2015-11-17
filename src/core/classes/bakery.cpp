//
// Created by ricardo on 05/10/15.
//

#include "bakery.h"


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

Bakery::~Bakery() {
    delete baker;
    delete yeast;
    delete updater;
    delete logbook;
}

unsigned int Bakery::get_id() const {
    return this->bakery_id;
}

const QString& Bakery::get_name() const {
    return bakery_name;
}

QString Bakery::get_state() const {
    return bakery_state;
}

QString Bakery::get_city() const {
    return bakery_city;
}

int Bakery::get_stock() const {
    return this->bakery_stock;
}


void Bakery::stop() {
    stopped = true;
}

const _operation& Bakery::get_current_op() const {
    return current_operation;
}


void Bakery::set_current_op(const _operation& operation) {
    this->current_operation = operation;
}

bool Bakery::is_closed_down() const {
    return stopped;
}

Baker* Bakery::get_baker() const {
    return baker;
}

void Bakery::mix_ingredients(int _start) {
    if(!stopped) {
//        LOG(DEBUG) << QString("Iniciando[%1]: %2").arg(bakery_id).arg("Mezcla de ingredientes").toStdString();
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

void Bakery::ferment_dough(int _start, bool _final_f) {
    if(!stopped) {
        qsrand((uint) QTime::currentTime().msec());

        int seconds;
        if(!_final_f) {
//            LOG(DEBUG) << QString("Iniciando[%1]: %2").arg(bakery_id).arg("Fermentación primaria").toStdString();
            this->current_operation.description = "Fermentación inicial de la masa";
            seconds = 15 + (qrand() % 10);
        } else {
//            LOG(DEBUG) << QString("Iniciando[%1]: %2").arg(bakery_id).arg("Fermentación final").toStdString();
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

void Bakery::divide_dough(int _start) {
    if(!stopped) {
//        LOG(DEBUG) << QString("Iniciando[%1]: %2").arg(bakery_id).arg("División de la masa").toStdString();
        qsrand((uint) QTime::currentTime().msec());

        this->current_operation.description = "Divisón de la masa";
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

void Bakery::shape_dough(int _start) {
    if(!stopped) {
//        LOG(DEBUG) << QString("Iniciando[%1]: %2").arg(bakery_id).arg("Formación de la masa").toStdString();
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

void Bakery::bake_bread(int _start) {
    if(!stopped) {
//        LOG(DEBUG) << QString("Iniciando[%1]: %2").arg(bakery_id).arg("Horneo del pan").toStdString();
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

void Bakery::sell_bread(int _start) {
    if(!stopped) {
//        LOG(DEBUG) << QString("Iniciando[%1]: %2").arg(bakery_id).arg("Venta del pan").toStdString();
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

void Bakery::distribute_bread(int _start) {
    if(!stopped) {
//        LOG(DEBUG) << QString("Iniciando[%1]: %2").arg(bakery_id).arg("Distribución del pan").toStdString();
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

void Bakery::resume_operations(void) {
    stopped = false;

    if(current_operation.progress / 100 == 11 || current_operation.progress / 100 == 8) {
        current_operation.progress = 0;
    }

    this->start();
    LOG(DEBUG) << "Bakery [" + to_string(bakery_id) + "] started";
}

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
 * Method called by the Ministry of Health when it
 * detects a sanity problem in a bakery.
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
 * Method called by the Baker in order to make the bakery
 * functional one more time after a close down.
 */
void Bakery::set_up(void) {
    stopped = false;

    /* The operation start from the beggining */
    current_operation.progress = 0;

    LOG(DEBUG) << "Bakery [" + to_string(bakery_id) + "] being set up";

    showInfoPopup("Panadería lista", bakery_name.toStdString() + " ha salido de cuarentena.");

    this->start();
}


void Bakery::select_notification() {
    static int have_not_sent_since = 0;
    qsrand((uint) QTime::currentTime().msec());

    if(((qrand() % 8) - 5) > 0 || have_not_sent_since > 5) {
        //then send it
        emit operation_changed(current_operation);
        have_not_sent_since = 0;
    } else {
        have_not_sent_since++;
    }
}

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
                    break;
                    emit operation_changed(current_operation);
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
