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

/**
 * Bakery class
 * Here all the bread production process occur in a sequential
 * way, every time a new process start the information corresponding
 * the new process starting is send to the API server.
 * Also, every single step inside a process is notified through a
 * signal to the GUI in order to perform the necessary GUI-refreshing.
 *
 * @author Ricardo Madriz
 */
class Bakery : public QThread {
Q_OBJECT
private:
    /**
     * The bakery id
     */
    unsigned int bakery_id;

    /**
     * The bakery name
     */
    QString bakery_name;

    /**
     * The bakery state.
     */
    QString bakery_state;

    /**
     * The bakery city.
     */
    QString bakery_city;

    /**
     * The bakery stock
     */
    int bakery_stock;

    /* Ops */

    /**
     * The current operation of the bakery.
     */
    _operation current_operation;

    /**
     * The bakery production status.
     */
    bool stopped;

    /**
     * Pointer to the baker that works in this bakery.
     */
    Baker* baker;

    /**
     * Pointer to the yeast used in this bakery.
     */
    Yeast* yeast;

    /**
     * Pointer to the logger used to send the status notification
     * to the server.
     */
    Logger* logbook;

    /**
     * Pointer to the stock updater.
     */
    ProductionUpdater* updater;

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
        updater = new ProductionUpdater;

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
        QObject::connect(this, &Bakery::updated_stock, updater, &ProductionUpdater::updater);

        QObject::connect(this, &Bakery::internal_oc, this, &Bakery::select_notification);
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

protected:
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

    /* Used to select whether a status update goes to upstream or not */
    void select_notification();

signals:
    void updated_stock(int, int);
    void internal_oc();
    void operation_changed(const _operation&);
    void notify_(int, QString);
};

#endif //BOLLO_BAKERY_H
