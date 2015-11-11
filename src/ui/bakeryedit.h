#ifndef BAKERYEDIT_H
#define BAKERYEDIT_H

#include <QDialog>
#include <QtNetwork/qnetworkaccessmanager.h>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtCore/qjsondocument.h>
#include <QtCore/qjsonobject.h>
#include <QDebug>

#include "../core/classes/bakery.h"

namespace Ui {

    class BakeryEdit;

    enum Mode {
       CREATE, MODIFY
    };

    enum Status {
        OK, ERROR
    };
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
    void setStatus(Ui::Mode , Ui::Status , QString );

private slots:
    void validateNewBakeInput();
    void validateEditBakeInput();
    void stateSelectChanged();

    void loadEditBakeryFields(int index);

    void saveBakery();
    void gotModifyReply(QNetworkReply *reply);

    void createBakery();
    void gotCreateReply(QNetworkReply *reply);

    void clearCreateFields();
    void clearEditStatus();
};

#endif // BAKERYEDIT_H
