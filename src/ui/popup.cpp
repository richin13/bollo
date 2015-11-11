#include "popup.h"
#include "ui_headers/ui_popup.h"
#include <QTimer>
#include <QDesktopWidget>

using namespace std;

Popup::Popup(QString title, QString msg, QWidget *parent) : QDialog(parent),
                                                             ui(new Ui::Popup) {

    ui->setupUi(this);
    applySettings();

    // Set title and message
    this->setWindowTitle(title);
    ui->message->setText(msg);

    // Show popup for 5 seconds and then close it.
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(close()));
    timer->start(TIME_MILIS);
}

void Popup::applySettings() {

    setAttribute(Qt::WA_ShowWithoutActivating);
    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint |
                   Qt::WindowDoesNotAcceptFocus | Qt::WindowStaysOnTopHint);

    setGeometry(QStyle::alignedRect(Qt::RightToLeft,Qt::AlignBottom,size(),
                                    qApp->desktop()->availableGeometry()));
}

void Popup::showPopup() {

    // Show popup for 5 seconds and then close it.
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(close()));

    show();
    timer->start(TIME_MILIS);
}

void Popup::close() {

    this->done(0);
}

Popup::~Popup() {

    delete ui;
}