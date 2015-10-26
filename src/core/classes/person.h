//
// Created by ricardo on 11/10/15.
//

#ifndef BOLLO_PERSON_H
#define BOLLO_PERSON_H

#include <QtCore/qstring.h>
#include "../build.h"

class Person {
private:
    int id;
    QString first_name;
    QString last_name;
    QString username;
    QString email;
    QString telegram;//TODO: Either the telegram number or the user.

public:
    Person();

    Person(int id, const QString &first_name,
           const QString &last_name,
           const QString &username,
           const QString &email,
           const QString &telegram = "") :
            id(id), first_name(first_name), last_name(last_name),
            username(username), email(email), telegram(telegram) { };

    int getId() const;

    void setId(int id);

    const QString &getFirst_name() const;

    void setFirst_name(const QString);

    const QString &getLast_name() const;

    void setLast_name(const QString);

    const QString &getUsername() const;

    void setUsername(const QString);

    const QString &getEmail() const;

    void setEmail(const QString);

    const QString &getTelegram() const;

    void setTelegram(const QString);
};


#endif //BOLLO_PERSON_H
