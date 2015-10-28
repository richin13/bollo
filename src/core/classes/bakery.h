//
// Created by ricardo on 05/10/15.
//

#ifndef BOLLO_BAKERY_H
#define BOLLO_BAKERY_H

#include <QtCore/qthread.h>
#include "../build.h"
#include "baker.h"

typedef unsigned short int integer_code;

typedef struct bakery_operation {
    unsigned int bakery_id;
    integer_code progress;
    QString description;
} operation;

class Bakery : public QObject {
Q_OBJECT
private:
    /* Basic information */
    unsigned int bakery_id;
    QString bakery_name;
    QString bakery_state;
    QString bakery_city;//address
    int bakery_stock;

    /* Ops */
    operation current_operation;
    bool closed_down;
    Baker* baker;//Baker thread
public:
    Bakery(){}
    Bakery(const Bakery&);
    ~Bakery();

    Bakery(unsigned int id,
           const QString& name,
           const QString& state,
           const QString& city,
            int stock, int progress, const QString& status) :
            bakery_id(id),
            bakery_name(name),
            bakery_state(state),
            bakery_city(city),
            bakery_stock(stock) {

        this->baker = new Baker();
        this->current_operation.bakery_id = this->bakery_id;
        this->current_operation.progress = (integer_code) progress;
        this->current_operation.description = status;

        connect(this, &Bakery::yeast, baker, &Baker::start_clean);//TODO: May fail
        connect(baker, &Baker::clean_ready, this, &Bakery::set_up);// this 1 too
    }

//Kinda unneeded
    unsigned int get_id() const;
    void set_id(unsigned int);
    const QString& get_name() const;
    void set_name(const QString&);
    QString get_state() const;
    void set_state(QString);
    QString get_city() const;
    void set_city(const QString&);
    int get_stock() const;
    void set_stock(int);

    const operation& get_current_op() const;
    void set_current_op(const operation&);
    bool is_closed_down() const;
    void set_closed_down(bool);
    Baker* get_baker() const;
    void set_baker(Baker*);


    /* Operations */
    void mix_ingredients(void);
    void ferment_dough(bool is_final = false);
    void divide_dough(void);
    void shape_dough(void);
    void bake_bread(void);
    void distribute_bread(void);
    void _run();
public slots:
    void close_down(void);
    void set_up(void);
signals:
    void operation_changed(const operation&);
    void yeast(int dough);
};


#endif //BOLLO_BAKERY_H
