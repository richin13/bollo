#include <QtWebKitWidgets/QWebView>
#include <QCommandLinkButton>

#include "selectpane.h"
#include "assets.h"
#include "ui_headers/ui_selectpane.h"
#include "../core/bollo.h"

// TODO: Add scroll area to bakeries list

SelectWindow::SelectWindow(QWidget *parent) : QWidget(parent),
                                              ui(new Ui::selectWindow) {

    ui->setupUi(this);

    buildBakeriesList();
}

SelectWindow::~SelectWindow() {

    delete ui;
}

/**
 * Checks if the bakeries list is empty, if it's notifies the user that
 * no bakeries are available, if its not empty build a button for each
 * bakery with the name, location an progress.
 */
void SelectWindow::buildBakeriesList() {

    int listSize = (int) BolloApp::get().bakeries.size();

    if (listSize != 0) {

        ui->noAvailableBakeries->setVisible(false);

        for(int i = 0; i < listSize; ++i) {

            addBakery(BolloApp::get().bakeries.at(i));
        }
    }

    else {

        ui->noAvailableBakeries->setVisible(true);
    }
}

void SelectWindow::addBakery(const Bakery& bakery) {

    QCommandLinkButton* button = new QCommandLinkButton();

    button->setText(bakery.get_name());
    button->setIcon(QIcon(Ui::SHOP_ICON));

    // Used to know which bakery is selected
    button->setAccessibleName(QString::number(bakery.get_id()));

    ui->bakeriesView->addWidget(button);
    ui->bakeriesView->addWidget(createHorizontalLine());

    connect(button, SIGNAL(clicked()), this, SLOT(bakeryButtonClicked()));
}

void SelectWindow::bakeryButtonClicked() {

    QCommandLinkButton* button = dynamic_cast<QCommandLinkButton*>(sender());

    emit bakerySelected(button->accessibleName().toInt());
}

QWidget* SelectWindow::createHorizontalLine() {

    QWidget *hLine = new QWidget;
    hLine->setFixedHeight(2);
    hLine->setFixedWidth(this->width() - MARGIN);
    hLine->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    hLine->setStyleSheet(QString("background-color: #c0c0c0;"));

    return hLine;
}

void SelectWindow::displayWebPage(QString url) {

    QWebView *viewer = new QWebView();
    QWebPage *page = viewer->page();
    QWebSettings *settings = page->settings();
    QUrl webPage = QUrl(url);

    settings->setAttribute(QWebSettings::JavascriptEnabled, true);
    settings->setAttribute(QWebSettings::PluginsEnabled, true);
    settings->setAttribute(QWebSettings::PrivateBrowsingEnabled , true);

    viewer->load(webPage);
    viewer->setFocus();
    viewer->show();

    ui->chartsWebView->setWidget(viewer);
}
