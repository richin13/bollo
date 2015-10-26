#include <QCommandLinkButton>

#include "bakeryselect.h"
#include "ui_headers/ui_bakeryselect.h"
#include "assets.h"

BakerySelect::BakerySelect(QWidget *parent) : QDialog(parent),
    ui(new Ui::bakerySelect) {

    ui->setupUi(this);

    addBakery("Panaderia penecito", "Amazando", 10);
}

BakerySelect::~BakerySelect() {

    delete ui;
}

void BakerySelect::checkAvailableBakeries() {

    /*
     * TODO: ADD "No hay panaderias disponibles" when all the backend
     * logic is implemented.
     */
}

void BakerySelect::addBakery(QString bakeryName, QString status, int progress) {

    QCommandLinkButton* button = new QCommandLinkButton();

    QString buttonDesc = bakeryName + " | Estado: " + status + " (" +
            QString::number(progress) + "%)";

    button->setText(buttonDesc);
    button->setIcon(QIcon(Ui::SHOP_ICON));

    ui->layout->addWidget(button);
    ui->layout->addWidget(createHorizontalLine());
}

QWidget* BakerySelect::createHorizontalLine() {

    QWidget *hLine = new QWidget;
    hLine->setFixedHeight(2);
    hLine->setFixedWidth(this->width() - MARGIN);
    hLine->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    hLine->setStyleSheet(QString("background-color: #c0c0c0;"));

    return hLine;
}
