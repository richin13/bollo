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

const QString &Person::getFirst_name() const {
    return this->first_name;
}

void Person::setFirst_name(const QString _fn) {
    this->first_name = _fn;
}

const QString &Person::getLast_name() const {
    return this->last_name;
}

void Person::setLast_name(const QString _ln) {
    this->last_name = _ln;
}

const QString &Person::getUsername() const {
    return this->username;
}

void Person::setUsername(const QString _un) {
    this->username = _un;
}

const QString &Person::getEmail() const {
    return this->email;
}

void Person::setEmail(const QString _email) {
    this->email = _email;
}

const QString &Person::getTelegram() const {
    return this->telegram;
}

void Person::setTelegram(const QString _telegram) {
    this->telegram = _telegram;
}
