#include <QCommandLinkButton>

#include "bakeryselect.h"
#include "ui_headers/ui_bakeryselect.h"
#include "assets.h"
#include "../core/bollo.h"

BakerySelect::BakerySelect(QWidget *parent) : QDialog(parent),
    ui(new Ui::bakerySelect) {

    ui->setupUi(this);
    createBakerisList();
}

BakerySelect::~BakerySelect() {

    delete ui;
}

/**
 * Checks if the bakeries list is empty, if it's notifies the user that
 * no bakeries are available, if its not empty build a button for each
 * bakery with the name, location an progress.
 */
void BakerySelect::createBakerisList() {

    int listSize = (int) BolloApp::get().bakeries.size();

    if (listSize != 0) {

        ui->noAvailableBakeries->setVisible(false);

        for(int i = 0; i < listSize; ++i) {

            addBakery(*(BolloApp::get().bakeries.at(i)));
        }
    }

    else {
        ui->noAvailableBakeries->setVisible(true);
    }
}

void BakerySelect::addBakery(const Bakery& bakery) {

    QCommandLinkButton* button = new QCommandLinkButton();

    QString formatted =
            QString("%1 (%2) | Estado: %3 (%4%)").arg(bakery.get_name(),
                                                     bakery.get_city(),
                                                     bakery.get_current_op().description,
                                                     QVariant(bakery.get_current_op().progress % 100).toString());

    button->setText(formatted);
    button->setIcon(QIcon(Ui::SHOP_ICON));

    // Used to know which bakery is selected
    button->setAccessibleName(QString::number(bakery.get_id()));

    ui->contents->layout()->addWidget(button);
    ui->contents->layout()->addWidget(createHorizontalLine());

    connect(button, SIGNAL(clicked()), this, SLOT(bakeryButtonClicked()));
}

/**
 * Custom slot which all the created bakeries buttons are connected to. Since this slot
 * is ONLY used to the bakeries button the sender object is casted to a QCommandLinkButton
 * (inherited by the bakeries button) then the button accessible name is extracted, in which
 * the bakery id was encapsulated. Then a "bakerySelected" signal is emmited with the selected
 * bakery id.
 */
void BakerySelect::bakeryButtonClicked() {

    QCommandLinkButton* button = dynamic_cast<QCommandLinkButton*>(sender());

    emit bakerySelected(button->accessibleName().toInt());
    this->close();
}

QWidget* BakerySelect::createHorizontalLine() {

    QWidget *hLine = new QWidget;
    hLine->setFixedHeight(2);
    hLine->setFixedWidth(this->width() - MARGIN);
    hLine->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    hLine->setStyleSheet(QString("background-color: #c0c0c0;"));

    return hLine;
}
