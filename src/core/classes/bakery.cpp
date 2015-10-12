//
// Created by ricardo on 05/10/15.
//

#include "bakery.h"

Bakery::Bakery() {
    //TODO
}

Bakery::Bakery(unsigned int id, string &name, unsigned short int state, string &city) {
    this->bakery_id = id;
    this->bakery_name = name;
    this->bakery_address_state = state;
    this->bakery_address_city = city;
}

Bakery::~Bakery() {
    //TODO
}

unsigned int Bakery::getBakery_id() const {
    return bakery_id;
}

void Bakery::setBakery_id(unsigned int bakery_id) {
    this->bakery_id = bakery_id;
}

const string &Bakery::getBakery_name() {
    return bakery_name;
}

void Bakery::setBakery_name(const string &bakery_name) {
    this->bakery_name = bakery_name;
}

unsigned short Bakery::getBakery_address_state() const {
    return bakery_address_state;
}

void Bakery::setBakery_address_state(unsigned short bakery_address_state) {
    this->bakery_address_state = bakery_address_state;
}

const string &Bakery::getBakery_address_city() {
    return bakery_address_city;
}

void Bakery::setBakery_address_city(const string &bakery_address_city) {
    this->bakery_address_city = bakery_address_city;
}