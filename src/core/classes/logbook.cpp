//
// Created by ricardo on 30/10/15.
//

#include "logbook.h"

int Logbook::get_id() const {
    return id;
}

void Logbook::setId(int id) {
    Logbook::id = id;
}

const QString& Logbook::getBakery() const {
    return bakery;
}

void Logbook::setBakery(const QString& bakery) {
    Logbook::bakery = bakery;
}

const QString& Logbook::getDescription() const {
    return description;
}

void Logbook::setDescription(const QString& description) {
    Logbook::description = description;
}

const QString& Logbook::getDate() const {
    return date;
}

void Logbook::setDate(const QString& date) {
    Logbook::date = date;
}

const QString& Logbook::getHour() const {
    return hour;
}

void Logbook::setHour(const QString& hour) {
    Logbook::hour = hour;
}


bool Logbook::operator==(const Logbook& logbook) {
    return id == logbook.get_id();
}

bool Logbook::operator==(const QString& _bak) {
    return bakery == _bak;
}

int LogbookProblem::get_dough() const {
    return dough;
}

void LogbookProblem::set_dough(int i) {
    LogbookProblem::dough = i;
}
