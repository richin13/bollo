//
// Created by ricardo on 10/11/15.
//

#ifndef BOLLO_BAKER_H
#define BOLLO_BAKER_H

#include <QtCore/qthread.h>
#include <QtCore/qdatetime.h>
#include <QtCore/qtimer.h>

#include "../../io/settings.h"
#include "../operations.h"
#include "../../ui/popup.h"

struct _operation;

class Baker : public QThread {
Q_OBJECT
private:
    QStringList pollutants;
public:
    Baker();

    virtual void run() override;
public slots:
    void find_pollutants(_operation);
    void start_clean(int);
signals:
    void clean_ready();
};


#endif //BOLLO_BAKER_H
