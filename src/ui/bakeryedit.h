#ifndef BAKERYEDIT_H
#define BAKERYEDIT_H

#include <QDialog>
#include "../core/classes/bakery.h"

namespace Ui {
class BakeryEdit;
}

class BakeryEdit : public QDialog {

    Q_OBJECT

public:
    explicit BakeryEdit(QWidget *parent = 0);
    ~BakeryEdit();

private:
    Ui::BakeryEdit *ui;
    Bakery* selectedBakery;

    void settings();
    void fillBakeryListComboBox();
    void connectEventChangeManagers();

private slots:
    void validateNewBakeInput();
    void validateEditBakeInput();
    void stateSelectChanged();

    void loadEditBakeryFields(int index);

    void saveBakery();
    void createBakery();
};

#endif // BAKERYEDIT_H
