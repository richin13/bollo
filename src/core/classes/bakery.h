//
// Created by ricardo on 05/10/15.
//

#ifndef BOLLO_BAKERY_H
#define BOLLO_BAKERY_H

#include <QtCore/qthread.h>
#include "../build.h"

typedef unsigned short int integer_code;

typedef struct bakery_operation {
    integer_code code;
    QString description;
} operation;

class Bakery : public QThread {//TODO: Is it a Thread?
Q_OBJECT
private:
    /* TODO: It must be a lightweight class in order to keep the performance
     * TODO: once there are a variable and vast amount of bakeries working
     * TODO: at the same time */
    unsigned int bakery_id;
    QString bakery_name;

    integer_code bakery_state;
    QString bakery_city;//address

    operation current_operation;
public:
    Bakery();

    Bakery(unsigned int id,
           QString name,
           integer_code state,
           QString &city) :
            bakery_id(id), bakery_name(name), bakery_state(state),
            bakery_city(city) { }

    ~Bakery();

    unsigned int getBakery_id() const;
    void setBakery_id(unsigned int);
    const QString &getBakery_name();
    void setBakery_name(const QString &);
    unsigned short getBakery_address_state() const;
    void setBakery_state(integer_code);
    const QString &getBakery_address_city();
    void setBakery_city(const QString &);

    //TODO: Add operations
    /*
        Mix ingredients.
        Fermentation of the dough.
        Divide dough.
        Shape the dough.
        Final fermentation of the dough.
        Bake bread.
        Distribute the bread.
     */
    void mix_ingredients(void);
    void fermentate_dough(bool _final = false);
    void divide_dough(void);
    void shape_dough(void);
    void bake_bread(void);
    void distribute_bread(void);

public slots:
    void close_down(void);
    void set_up(void);
signals:
    void operation_changed(const operation &);//TODO: test if const struct can have its members modified.

};


#endif //BOLLO_BAKERY_H
