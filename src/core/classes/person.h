//
// Created by ricardo on 11/10/15.
//

#ifndef BOLLO_PERSON_H
#define BOLLO_PERSON_H

#include <QtCore/qstring.h>

class Person {

private:

    /**
     * The person's id.
     */
    int id;

    /**
     * The person's first name.
     */
    QString first_name;

    /**
     * The person's last name.
     */
    QString last_name;

    /**
     * The person's username.
     */
    QString username;

    /**
     * The person's email.
     */
    QString email;

public:
    /**
     * @brief Empty constructor of the class.
     */
    Person();

    /**
     * @brief Parametrized constructor of the class
     * @param id The id
     * @param first_name The first name.
     * @param last_name The last name.
     * @param username The username.
     * @param email The email address.
     */
    Person(int id, const QString &first_name,
           const QString &last_name,
           const QString &username,
           const QString& email) :
            id(id), first_name(first_name), last_name(last_name),
            username(username), email(email) { };

    int getId() const;

    const QString &getFirst_name() const;

    const QString &getLast_name() const;

    const QString &getUsername() const;

    const QString &getEmail() const;
};


#endif //BOLLO_PERSON_H
