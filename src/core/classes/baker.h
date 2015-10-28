//
// Created by ricardo on 17/10/15.
//

#ifndef BOLLO_BAKER_H
#define BOLLO_BAKER_H


#include <QtCore/qthread.h>

class Baker : public QThread {
Q_OBJECT
public:
    Baker() { }
    ~Baker(){}

    virtual void run() override;
public slots:
    void start_clean(int);
signals:
    void clean_ready();
};


#endif //BOLLO_BAKER_H
