//
// Created by ricardo on 05/10/15.
//

#ifndef BOLLO_BAKERY_H
#define BOLLO_BAKERY_H

#include <QtCore/qthread.h>
#include <QtCore/qtimer.h>
#include <QtCore/qdatetime.h>

#include "baker.h"
#include "yeast.h"
#include "ministry.h"
#include "../operations.h"
#include "../../logger/logger.h"
#include "../../ui/popup.h"
#include "../../io/production_updater.h"

#define LAPSE_TIME 90000

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

    Logger* logbook;
    StockUpdater* updater;
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

        logbook = new Logger;
        baker = new Baker(bakery_name);
        yeast = new Yeast;
        updater = new StockUpdater;

        current_operation.bakery_id = this->bakery_id;
        current_operation.progress = (integer_code) progress;
        current_operation.description = status;
        current_operation.stock = stock;

        this->stopped = progress / 100 == 8 || progress / 100 == 11;

        QObject::connect(this, &Bakery::operation_changed, baker, &Baker::find_pollutants);
        QObject::connect(baker, &Baker::clean_ready, this, &Bakery::set_up);

        QObject::connect(this, &Bakery::operation_changed, yeast, &Yeast::select_yeast);
        QObject::connect(yeast, &Yeast::contaminated_yeast, this, &Bakery::bad_yeast);


        QObject::connect(this, &Bakery::notify_, logbook, &Logger::send_logbook_entry);
        QObject::connect(this, &Bakery::updated_stock, updater, &StockUpdater::updater);


    }

    unsigned int get_id() const;
    const QString& get_name() const;
    QString get_state() const;
    QString get_city() const;
    int get_stock() const;
    void stop();

    const _operation& get_current_op() const;
    void set_current_op(const _operation&);
    bool is_closed_down() const;
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
    void updated_stock(int, int);
    void operation_changed(const _operation&);
    void notify_(int, QString);
};

#endif //BOLLO_BAKERY_H
