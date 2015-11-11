//
// Created by ricardo on 05/10/15.
//

#ifndef BOLLO_BAKERY_H
#define BOLLO_BAKERY_H

#include <QtCore/qthread.h>
#include <QtCore/qtimer.h>
#include <QtCore/qdatetime.h>

#include "../bollo.h"
#include "../../logger/logger.h"
#include "../../ui/popup.h"
#include "baker.h"
#include "../operations.h"
#include "yeast.h"

class Bakery : public QThread {
Q_OBJECT
private:
    /* Basic information */
    unsigned int bakery_id;
    QString bakery_name;
    QString bakery_state;
    QString bakery_city;//address
    int bakery_stock;

    /* Ops */
    _operation current_operation;
    bool stopped;

    Baker* baker;//Baker thread
    Yeast* yeast;//Bad yeast thread

    /* Logbook handler */
//    Logger logbook;
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

        baker = new Baker(bakery_name);
        yeast = new Yeast;

        current_operation.bakery_id = this->bakery_id;
        current_operation.progress = (integer_code) progress;
        current_operation.description = status;
        current_operation.stock = stock;

        this->stopped = progress / 100 == 8;

        QObject::connect(this, &Bakery::operation_changed, baker, &Baker::find_pollutants);
        QObject::connect(baker, &Baker::clean_ready, this, &Bakery::set_up);

        QObject::connect(this, &Bakery::operation_changed, yeast, &Yeast::select_yeast);
        QObject::connect(yeast, &Yeast::contaminated_yeast, this, &Bakery::bad_yeast);


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

    const _operation& get_current_op() const;
    bool is_closed_down() const;
    void set_closed_down(bool);
    Baker* get_baker() const;


    /* Operations */
    void mix_ingredients(int _start = 0);
    void ferment_dough(int _start = 0, bool is_final = false);
    void divide_dough(int _start = 0);
    void shape_dough(int _start = 0);
    void bake_bread(int _start = 0);
    void sell_bread(int _start = 0);
    void distribute_bread(int _start = 0);

    void run() Q_DECL_OVERRIDE;
public slots:

    /* Called by GUI buttons */
    void stop_operations(bool f = false);
    void resume_operations(void);

    /* Called by Yeast thread */
    void bad_yeast(void);

    /* Called by Ministry of health and the like */
    void close_down(void);
    void set_up(void);
signals:
    void operation_changed(const _operation&);
};

#endif //BOLLO_BAKERY_H
