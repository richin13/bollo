//
// Created by ricardo on 30/10/15.
//

#include "logbook.h"

int Logbook::get_id() const {
    return id;
}

const QString& Logbook::getBakery() const {
    return bakery;
}

int Logbook::getBakeryId() const {
    return bakery_id;
}

const QString& Logbook::getDescription() const {
    return description;
}

const QString& Logbook::getDate() const {
    return date;
}

const QString& Logbook::getHour() const {
    return hour;
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
