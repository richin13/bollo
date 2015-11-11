#ifndef POPUP_H
#define POPUP_H

#include <QDialog>
#include <QString>
namespace Ui {

    class Popup;

    #define TIME_MILIS 5000
}

class Popup : public QDialog {

    Q_OBJECT

public:
    Popup(QString title, QString msg, QWidget *parent = 0);
    ~Popup();

    void showPopup();

private slots:
    void close();

private:
    Ui::Popup *ui;

    void applySettings();
};

#endif // POPUP_H
