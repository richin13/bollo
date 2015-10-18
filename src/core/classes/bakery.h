//
// Created by ricardo on 05/10/15.
//

#ifndef BOLLO_BAKERY_H
#define BOLLO_BAKERY_H

#include <QtCore/qthread.h>
#include "../build.h"

typedef unsigned short int integer_code;

typedef struct bakery_operation {
    unsigned int bakery_id;
    integer_code progress;
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
    bool closed_down;
public:
    Bakery();
    ~Bakery();
    Bakery(unsigned int id,
           QString name,
           integer_code state,
           QString& city) :
            bakery_id(id), bakery_name(name), bakery_state(state),
            bakery_city(city) {
        this->current_operation.bakery_id = this->bakery_id;
    }

    unsigned int get_id() const;
    void set_id(unsigned int);
    const QString& get_name();
    void set_name(const QString&);
    unsigned short get_state() const;
    void set_state(integer_code);
    const QString& get_city();
    void set_city(const QString&);

    /* Operations */
    void mix_ingredients(void);
    void ferment_dough(bool is_final = false);
    void divide_dough(void);
    void shape_dough(void);
    void bake_bread(void);
    void distribute_bread(void);

protected:
    virtual void run() override;
public slots:
    void close_down(void);
    void set_up(void);
signals:
    void operation_changed(const operation&);
    void yeast(int dough);
};


#endif //BOLLO_BAKERY_H
