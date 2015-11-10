//
// Created by Daniel on 09/11/15.
//

#ifndef BOLLO_ABOUT_H
#define BOLLO_ABOUT_H

#include <QDialog>

namespace Ui {

    class About;

#define TIME_MILIS 5000
}

class About : public QDialog {

    Q_OBJECT

public:
    About(QWidget *parent = 0);
    ~About();

private:
    Ui::About *ui;
};

#endif //BOLLO_ABOUT_H
