//
// Created by ricardo on 17/10/15.
//

#ifndef BOLLO_BAKER_H
#define BOLLO_BAKER_H


#include <QtCore/qthread.h>
#include "bakery.h"

class Baker : public QThread {
Q_OBJECT
private:
    Bakery workplace;

public:
    Baker(Bakery& _workplace) : workplace(_workplace) {
        connect(this, Baker::clean_ready, workplace, &Bakery::set_up);
        connect(workplace, &Bakery::yeast, this, Baker::start_clean);//FIXME: May fail SIGSV

    }

    virtual void run() override;
public slots:
    void start_clean(int);
signals:
    void clean_ready();
};


#endif //BOLLO_BAKER_H
