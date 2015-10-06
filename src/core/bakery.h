//
// Created by ricardo on 05/10/15.
//

#ifndef BOLLO_BAKERY_H
#define BOLLO_BAKERY_H

#include <QtCore/qthread.h>
#include "build.h"

class Bakery : public QThread {
Q_OBJECT

    unsigned int bakery_id;
    string bakery_name;
    unsigned short int bakery_address_state;
    //provincia
    string bakery_address_city;//address

public:
    Bakery();

    Bakery(unsigned int, string &, unsigned short int, string &);

    ~Bakery();

    unsigned int getBakery_id() const;

    void setBakery_id(unsigned int);

    const string &getBakery_name();

    void setBakery_name(const string &);

    unsigned short getBakery_address_state() const;

    void setBakery_address_state(unsigned short);

    const string &getBakery_address_city();

    void setBakery_address_city(const string &);

    //FIXME:Pending to add operations
};


#endif //BOLLO_BAKERY_H
