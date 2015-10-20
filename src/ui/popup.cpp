#include "popup.h"
#include "ui_headers/ui_popup.h"
#include <QString>
#include <QDesktopWidget>
#include <unistd.h>

using namespace std;

//TODO Close notification in n seconds.

Popup::Popup(QWidget *parent) : QDialog(parent),
    ui(new Ui::Popup) {

    ui->setupUi(this);

    setAttribute(Qt::WA_ShowWithoutActivating);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint |
                   Qt::WindowDoesNotAcceptFocus | Qt::WindowStaysOnTopHint);

}

void Popup::showPopup (QString title, QString message) {

    // Set title and message
    ui->title->setText(title);
    ui->message->setText(message);

    setGeometry(QStyle::alignedRect(Qt::RightToLeft,Qt::AlignBottom,size(),
                qApp->desktop()->availableGeometry()));

    show();
}

Popup::~Popup() {

    delete ui;
}

void Popup::on_closeButton_clicked() {

    close();
}
