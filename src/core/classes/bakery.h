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

class Bakery : public QThread {
Q_OBJECT
private:
    /* Basic information */
    unsigned int bakery_id;
    QString bakery_name;
    integer_code bakery_state;
    QString bakery_city;//address

    /* Ops */
    operation current_operation;
    bool closed_down;
    Baker* baker;//Baker thread
public:
    Bakery();
    ~Bakery();

    Bakery(unsigned int id,
           QString name,
           integer_code state,
           QString& city) :
            bakery_id(id), bakery_name(name), bakery_state(state),
            bakery_city(city) {
        this->baker = new Baker();
        this->current_operation.bakery_id = this->bakery_id;
        connect(this, &Bakery::yeast, baker, &Baker::start_clean);//TODO: May fail
        connect(baker, &Baker::clean_ready, this, &Bakery::set_up);// this 1 too
    }

//Kinda unneeded
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
