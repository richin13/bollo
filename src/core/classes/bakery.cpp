//
// Created by ricardo on 05/10/15.
//

#include "bakery.h"

Bakery::Bakery() {
    //TODO
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

const QString& Bakery::get_name() {
    return bakery_name;
}

void Bakery::set_name(const QString& bakery_name) {
    this->bakery_name = bakery_name;
}

unsigned short Bakery::get_state() const {
    return bakery_state;
}

void Bakery::set_state(unsigned short bakery_address_state) {
    this->bakery_state = bakery_address_state;
}

const QString& Bakery::get_city() {
    return bakery_city;
}

void Bakery::set_city(const QString& bakery_city) {
    this->bakery_city = bakery_city;
}

void Bakery::mix_ingredients(void) {
    this->current_operation.progress = 0;
    this->current_operation.description = "Mezcla de ingredientes";
    emit operation_changed(current_operation);
    int seconds = 25;//TODO: Must be configurable.
    for(int i = 0; i < 100; ++i) {
        this->current_operation.progress += 1;
        emit operation_changed(current_operation);
        QThread::usleep((unsigned long) (seconds * 10));
    }
    //TODO: Missing logging operation
}

void Bakery::ferment_dough(bool _final_f) {
    int seconds;
    if(!_final_f) {
        this->current_operation.description = "Fermentación de la masa";
        seconds = 20;
    } else {
        this->current_operation.description = "Fermentación final de la masa";
        seconds = 25;
    }

    emit operation_changed(this->current_operation);
    for(int i = 0; i < 100; ++i) {
        this->current_operation.progress += 1;
        emit operation_changed(current_operation);
        QThread::usleep((unsigned long) (seconds * 10));
    }
    //TODO: Missing logging operation
}

void Bakery::divide_dough(void) {
    this->current_operation.description = "Divisón de la masa";
    int seconds = 20;
    emit operation_changed(current_operation);

    for(int i = 0; i < 100; ++i) {
        this->current_operation.progress += 1;
        emit operation_changed(current_operation);
        QThread::usleep((unsigned long) (seconds * 10));
    }
    //TODO: Missing logging operation
}

void Bakery::shape_dough(void) {
    this->current_operation.description = "Formar la masa";//FIXME: Ugly!
    int seconds = 35;
    emit operation_changed(current_operation);

    for(int i = 0; i < 100; ++i) {
        this->current_operation.progress += 1;
        emit operation_changed(current_operation);
        QThread::usleep((unsigned long) (seconds * 10));
    }
}

void Bakery::bake_bread(void) {
    this->current_operation.description = "Horneo del pan";
    int seconds = 40;
    emit operation_changed(current_operation);

    for(int i = 0; i < 100; ++i) {
        this->current_operation.progress += 1;
        emit operation_changed(current_operation);
        QThread::usleep((unsigned long) (seconds * 10));
    }
    //TODO: Missing logging operation
}

void Bakery::distribute_bread(void) {
    this->current_operation.description = "Distribución del pan";
    int seconds = 20;
    emit operation_changed(current_operation);

    for(int i = 0; i < 100; ++i) {
        this->current_operation.progress += 1;
        emit operation_changed(current_operation);
        QThread::usleep((unsigned long) (seconds * 10));
    }
    //TODO: Missing logging operation
}

/**
 * Method called by the Ministry of Health when it
 * detects a sanity problem in a bakery.
 */
void Bakery::close_down(void) {

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
    this->start();
}

void Bakery::run() {
    while(!closed_down) {
        mix_ingredients();
        ferment_dough();
        divide_dough();
        shape_dough();
        ferment_dough(true);
        bake_bread();
        distribute_bread();
    }
}
