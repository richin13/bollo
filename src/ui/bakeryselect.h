#ifndef BAKERYSELECT_H
#define BAKERYSELECT_H

#include <QDialog>
#include "../core/classes/bakery.h"

namespace Ui {

#define MARGIN 35

class bakerySelect;
}

class BakerySelect : public QDialog {
    Q_OBJECT

public:
    explicit BakerySelect(QWidget *parent = 0);
    ~BakerySelect();

private:
    Ui::bakerySelect *ui;

    void checkAvailableBakeries();

    void addBakery(const Bakery&);
    QWidget* createHorizontalLine();
};

#endif // BAKERYSELECT_H
