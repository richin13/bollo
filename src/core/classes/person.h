//
// Created by ricardo on 11/10/15.
//

#ifndef BOLLO_PERSON_H
#define BOLLO_PERSON_H

#include "../build.h"

class Person {
private:
    int id;
    string first_name;
    string last_name;
    string username;
    string email;
    string telegram;//TODO: Either the telegram number or the user.

public:
    Person();

    Person(int id, const string &first_name,
           const string &last_name,
           const string &username,
           const string &email,
           const string &telegram) :
            id(id), first_name(first_name), last_name(last_name),
            username(username), email(email), telegram(telegram) { };

    int getId() const;

    void setId(int id);

    const string &getFirst_name() const;

    void setFirst_name(const string);

    const string &getLast_name() const;

    void setLast_name(const string);

    const string &getUsername() const;

    void setUsername(const string);

    const string &getEmail() const;

    void setEmail(const string);

    const string &getTelegram() const;

    void setTelegram(const string);
};


#endif //BOLLO_PERSON_H
