//
// Created by ricardo on 10/11/15.
//

#ifndef BOLLO_BAKER_H
#define BOLLO_BAKER_H

#include <QtCore/qthread.h>
#include <QtCore/qdatetime.h>
#include <QtCore/qtimer.h>

#include "../operations.h"
#include "../../logger/logger.h"
#include "../../io/settings.h"
#include "../../ui/popup.h"

struct _operation;

class Baker : public QThread {
Q_OBJECT
private:
    Logger* logbook;

    QString bakery_name;
    QStringList pollutants;
public:
    Baker(const QString _name) : bakery_name(_name) {
        pollutants.append("levadura mala");
        pollutants.append("bacterias");
        pollutants.append("coliformes");
        pollutants.append("otros contaminantes");

        logbook = new Logger;
        QObject::connect(this, &Baker::found_pollutants, logbook, &Logger::send_logbook_problem);
    }

    ~Baker() {
        delete logbook;
        LOG(DEBUG) << "Deallocated memory of Baker class";
    }

    virtual void run() override;
public slots:
    void find_pollutants(_operation);
    void start_clean();
signals:
    void found_pollutants(int, QString, int);
    void clean_ready();
};


#endif //BOLLO_BAKER_H
