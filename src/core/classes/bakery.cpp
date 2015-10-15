//
// Created by ricardo on 05/10/15.
//

#include "bakery.h"

Bakery::Bakery() {
    //TODO
}

Bakery::~Bakery() {
    //TODO
}

unsigned int Bakery::getBakery_id() const {
    return this->bakery_id;
}

void Bakery::setBakery_id(unsigned int bakery_id) {
    this->bakery_id = bakery_id;
}

const QString &Bakery::getBakery_name() {
    return bakery_name;
}

void Bakery::setBakery_name(const QString &bakery_name) {
    this->bakery_name = bakery_name;
}

unsigned short Bakery::getBakery_address_state() const {
    return bakery_state;
}

void Bakery::setBakery_state(unsigned short bakery_address_state) {
    this->bakery_state = bakery_address_state;
}

const QString &Bakery::getBakery_address_city() {
    return bakery_city;
}

void Bakery::setBakery_city(const QString &bakery_city) {
    this->bakery_city = bakery_city;
}

void Bakery::mix_ingredients(void) {

}

void Bakery::fermentate_dough(bool _final){

}

void Bakery::divide_dough(void) {

}

void Bakery::shape_dough(void) {

}

void Bakery::bake_bread(void) {

}

void Bakery::distribute_bread(void) {

}

void Bakery::operation_changed(const operation &operation1) {

}
