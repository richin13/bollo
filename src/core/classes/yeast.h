//
// Created by ricardo on 18/10/15.
//

#ifndef BOLLO_YEAST_H
#define BOLLO_YEAST_H


#include <QtCore/qthread.h>

class Yeast : public QThread {
Q_OBJECT
private:
    bool on;
public:
    Yeast();
    virtual void run() override;

public slots:
    void select_yeast(void);
signals:
    void contaminated_yeast(void);
};


#endif //BOLLO_YEAST_H
