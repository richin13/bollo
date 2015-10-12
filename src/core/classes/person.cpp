//
// Created by ricardo on 11/10/15.
//

#include "person.h"

Person::Person() { }

int Person::getId() const {
    return this->id;
}

void Person::setId(int _id) {
    this->id = _id;
}

const string &Person::getFirst_name() const {
    return this->first_name;
}

void Person::setFirst_name(const string _fn) {
    this->first_name = _fn;
}

const string &Person::getLast_name() const {
    return this->last_name;
}

void Person::setLast_name(const string _ln) {
    this->last_name = _ln;
}

const string &Person::getUsername() const {
    return this->username;
}

void Person::setUsername(const string _un) {
    this->username = _un;
}

const string &Person::getEmail() const {
    return this->email;
}

void Person::setEmail(const string _email) {
    this->email = _email;
}

const string &Person::getTelegram() const {
    return this->telegram;
}

void Person::setTelegram(const string _telegram) {
    this->telegram = _telegram;
}
