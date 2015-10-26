#ifndef POPUP_H
#define POPUP_H

#include <QDialog>
#include <QString>
namespace Ui {

class Popup;
}

class Popup : public QDialog {

    Q_OBJECT

public:
    explicit Popup(QWidget *parent = 0);
    void showPopup (QString title, QString message);
    ~Popup();

private slots:
    void on_closeButton_clicked();

private:
    Ui::Popup *ui;
};

#endif // POPUP_H
