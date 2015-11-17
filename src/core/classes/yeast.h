//
// Created by ricardo on 18/10/15.
//

#ifndef BOLLO_YEAST_H
#define BOLLO_YEAST_H


#include <QtCore/qthread.h>
#include "../operations.h"

/**
 * The yeast thread is a special thread that affects the normal
 * process of bread production.
 *
 * IRL: When the ingredients of bread are being mixed the yeast is
 * included but only at fermentation stage we realize that the yeast
 * used is damaged.
 * Here, we simulate that exact process by selecting the yeast to
 * be used at 'Mixing ingredients' stage but showing the negatives
 * effects once the bread is at 'Fermentation stage'.
 *
 * @author Ricardo Madriz
 */
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
     * Empty constructor of class.
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
