//
// Created by ricardo on 18/10/15.
//

#ifndef BOLLO_YEAST_H
#define BOLLO_YEAST_H


#include <QtCore/qthread.h>
#include "../operations.h"

class Yeast : public QThread {
Q_OBJECT
private:

    /**
     * A flag that determines whether the yeast is
     * contaminated or not.
     */
    bool contaminated;

public:
    /**
     * @brief Empty constructor of class.
     */
    Yeast() {
        contaminated = false;
    }

    virtual void run() override;

    bool isContaminated() const;

public slots:
    void select_yeast(_operation);
signals:
    void contaminated_yeast(void);
};


#endif //BOLLO_YEAST_H
