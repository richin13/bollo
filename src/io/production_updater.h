//
// Created by ricardo on 14/11/15.
//

#include <QtCore/qobject.h>

#ifndef BOLLO_STOCK_UPDATER_H
#define BOLLO_STOCK_UPDATER_H

/**
 * Class used to communicate with the API server to notify
 * about bakery's production.
 *
 * @author Ricardo Madriz
 */
class ProductionUpdater : public QObject {
Q_OBJECT

public slots:
    void updater(int bid, int quantity);
};

#endif //BOLLO_STOCK_UPDATER_H
