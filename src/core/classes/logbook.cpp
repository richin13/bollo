//
// Created by ricardo on 30/10/15.
//

#include "logbook.h"

/**
 *  Gets the logbook entry id.
 * @return The logbook entry id
 */
int Logbook::get_id() const {
    return id;
}

/**
 *  Gets the name of the bakery corresponding to the logbook entry.
 * @return The name of the bakery corresponding to the logbook entry
 */
const QString& Logbook::getBakery() const {
    return bakery_name;
}

/**
 *  Gets the id of the bakery corresponding to the logbook entry.
 * @return The id of the bakery corresponding to the logbook entry
 */
int Logbook::getBakeryId() const {
    return bakery_id;
}

/**
 *  Gets the logbook entry description.
 * @return The logbook entry description
 */
const QString& Logbook::getDescription() const {
    return description;
}

/**
 *  Gets the logbook entry date.
 * @return The logbook entry date
 */
const QString& Logbook::getDate() const {
    return date;
}

/**
 *  Gets the logbook entry hour.
 * @return The logbook entry hour
 */
const QString& Logbook::getHour() const {
    return hour;
}

bool Logbook::operator==(const Logbook& logbook) {
    return id == logbook.get_id();
}

bool Logbook::operator==(const QString& _bak) {
    return bakery_name == _bak;
}

/**
 *  Gets the amount of dough affected.
 * @return The the amount of dough affected.
 */
int LogbookProblem::get_dough() const {
    return dough;
}

/**
 *  Sets the amount of dough affected.
 * @param The amount of dough affected to be set.
 */
void LogbookProblem::set_dough(int i) {
    LogbookProblem::dough = i;
}
