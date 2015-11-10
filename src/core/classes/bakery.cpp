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
    closed_down = cpy.is_closed_down();
    baker = cpy.get_baker();
}

Bakery::~Bakery() {
    delete baker;
}

unsigned int Bakery::get_id() const {
    return this->bakery_id;
}

void Bakery::set_id(unsigned int bakery_id) {
    this->bakery_id = bakery_id;
}

const QString& Bakery::get_name() const {
    return bakery_name;
}

void Bakery::set_name(const QString& bakery_name) {
    this->bakery_name = bakery_name;
}

QString Bakery::get_state() const {
    return bakery_state;
}

void Bakery::set_state(QString bakery_state) {
    this->bakery_state = bakery_state;
}

QString Bakery::get_city() const {
    return bakery_city;
}

void Bakery::set_city(const QString& bakery_city) {
    this->bakery_city = bakery_city;
}

int Bakery::get_stock() const {
    return this->bakery_stock;
}

void Bakery::set_stock(int stock) {
    this->bakery_stock = stock;
}

const _operation& Bakery::get_current_op() const {
    return current_operation;
}

bool Bakery::is_closed_down() const {
    return closed_down;
}

void Bakery::set_closed_down(bool closed_down) {
    Bakery::closed_down = closed_down;
}

Baker* Bakery::get_baker() const {
    return baker;
}

void Bakery::mix_ingredients(int _start) {
    this->current_operation.progress = (integer_code) _start;
    this->current_operation.description = "Mezclando los ingredientes";
    logbook.general(this->bakery_id) << current_operation.description;
    int seconds = 25;//TODO: Must be configurable.
    for(int i = _start; i < 100; ++i) {
        emit operation_changed(current_operation);
        this->current_operation.progress += 1;
        QThread::usleep((unsigned long) (seconds * 100000));
    }
    std::cout << "Final value of progress --->>> " << current_operation.progress << std::endl;
}

void Bakery::ferment_dough(int _start, bool _final_f) {
    int seconds;
    if(!_final_f) {
        this->current_operation.description = "Fermentación inicial de la masa";
        seconds = 20;
    } else {
        this->current_operation.description = "Fermentación final de la masa";
        seconds = 25;
    }
    logbook.general(this->bakery_id) << current_operation.description;
    for(int i = _start; i < 100; ++i) {
        emit operation_changed(current_operation);
        this->current_operation.progress += 1;
        QThread::usleep((unsigned long) (seconds * 100000));
    }
}

void Bakery::divide_dough(int _start) {
    this->current_operation.description = "Divisón de la masa";
    logbook.general(this->bakery_id) << current_operation.description;
    int seconds = 20;

    for(int i = _start; i < 100; ++i) {
        emit operation_changed(current_operation);
        this->current_operation.progress += 1;
        QThread::usleep((unsigned long) (seconds * 100000));
    }
}

void Bakery::shape_dough(int _start) {
    this->current_operation.description = "Formando la masa";
    logbook.general(this->bakery_id) << current_operation.description;
    int seconds = 35;

    for(int i = _start; i < 100; ++i) {
        emit operation_changed(current_operation);
        this->current_operation.progress += 1;
        QThread::usleep((unsigned long) (seconds * 100000));
    }
}

void Bakery::bake_bread(int _start) {
    this->current_operation.description = "Horneando el pan";
    logbook.general(this->bakery_id) << current_operation.description;
    int seconds = 40;

    for(int i = _start; i < 100; ++i) {
        emit operation_changed(current_operation);
        this->current_operation.progress += 1;
        QThread::usleep((unsigned long) (seconds * 100000));
    }
}

void Bakery::sell_bread(int _start) {
    this->current_operation.description = "Vendiendo el pan";
    logbook.general(this->bakery_id) << current_operation.description;
    int seconds = 35;

    for(int i = _start; i < 100; ++i) {
        emit operation_changed(current_operation);
        this->current_operation.progress += 1;
        QThread::usleep((unsigned long) (seconds * 100000));
    }
}

void Bakery::distribute_bread(int _start) {
    this->current_operation.description = "Distribuyendo el pan";
    logbook.general(this->bakery_id) << current_operation.description;
    int seconds = 20;

    for(int i = _start; i < 100; ++i) {
        emit operation_changed(current_operation);
        this->current_operation.progress += 1;
        QThread::usleep((unsigned long) (seconds * 100000));
    }
}

/**
 * Method called by the Ministry of Health when it
 * detects a sanity problem in a bakery.
 */
void Bakery::close_down(void) {

    Popup* p = new Popup("Panadería clausarada", bakery_name + " ha sido clausurada");
    p->show();
    QObject::connect(p, SIGNAL(destroyed()), p, SLOT(deleteLater()));
}

/**
 * Method called by the Baker in order to make the bakery
 * functional one more time after a close down.
 */
void Bakery::set_up(void) {
    closed_down = false;
    current_operation.progress = 0;
    current_operation.description = "";
    /* TODO: Should emmit a signal saying: "Hey, I am ready"
        so we can notify, through the UI or, why not, an email to
        the administrator.
     */
//    this->start();
}

void Bakery::run() {
    LOG(DEBUG) << "Starting bakery thread[" + to_string(bakery_id) + "]";
    bool first_time = true;
    while(!closed_down) {
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
                default:
                    LOG(WARNING) << "Other than options established above would be unnexpected at this point";
            }
        }

        mix_ingredients();
        ferment_dough();
        divide_dough();
        shape_dough();
        ferment_dough(true);
        bake_bread();
        sell_bread();
        distribute_bread();
    }
}
