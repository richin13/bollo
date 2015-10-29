#include <QCommandLinkButton>

#include "bakeryselect.h"
#include "ui_headers/ui_bakeryselect.h"
#include "assets.h"
#include "../core/bollo.h"

BakerySelect::BakerySelect(QWidget *parent) : QDialog(parent),
    ui(new Ui::bakerySelect) {

    ui->setupUi(this);

    int size = (int) BolloApp::get().bakeries.size();
    for(int i = 0; i < size; ++i) {
        addBakery(BolloApp::get().bakeries.at(i));
    }
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

void BakerySelect::addBakery(const Bakery& bakery) {

    QCommandLinkButton* button = new QCommandLinkButton();

    QString formatted =
            QString("%1 - %2| Estado: %3 (%4%)").arg(bakery.get_name(),
                                                     bakery.get_city(),
                                                     bakery.get_current_op().description,
                                                     QVariant(bakery.get_current_op().progress % 100).toString());

    button->setText(formatted);
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
