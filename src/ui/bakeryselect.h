#ifndef BAKERYSELECT_H
#define BAKERYSELECT_H

#include <QDialog>

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

    void addBakery(QString , QString, int);
    QWidget* createHorizontalLine();
};

#endif // BAKERYSELECT_H
