//
// Created by ricardo on 11/10/15.
//

#include "person.h"

Person::Person() { }

/**
 * Gets the person's id.
 * @return The person id.
 */
int Person::getId() const {
    return this->id;
}

/**
 * Gets the person's first name.
 * @return The person first name.
 */
const QString &Person::getFirst_name() const {
    return this->first_name;
}

/**
 * Gets the person's last name.
 * @return The person last name.
 */
const QString &Person::getLast_name() const {
    return this->last_name;
}

/**
 * Gets the person's username.
 * @return The person username.
 */
const QString &Person::getUsername() const {
    return this->username;
}

/**
 * Gets the person's email address.
 * @return The person email address.
 */
const QString &Person::getEmail() const {
    return this->email;
}