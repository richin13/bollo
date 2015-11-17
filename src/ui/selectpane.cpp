/**
 * @author Daniel Aguilar
 *
 * Shows a bakery list and chart viewer to the user after a successful login.
 */

#include <QtWebKitWidgets/QWebView>
#include <QCommandLinkButton>

#include "selectpane.h"
#include "assets.h"
#include "ui_headers/ui_selectpane.h"

SelectWindow::SelectWindow(QWidget *parent) : QWidget(parent),
                                              ui(new Ui::selectWindow) {

    ui->setupUi(this);

    buildBakeriesList();
}

SelectWindow::~SelectWindow() {

    LOG(DEBUG) << "Select pane deleted";

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

            addBakery(*(BolloApp::get().bakeries.at(i)));
        }
    }

    else {

        ui->noAvailableBakeries->setVisible(true);
    }
}

/**
 * Creates a custom QCommandLinkButton and then added to the bakeriesView. After
 * the button is added a Horizontal line is added to separate each bakery button, also
 * the bakery id is assigned to the button accessible name, to know which bakery was selected.
 * Finally the buttons is connected to the slot.
 */
void SelectWindow::addBakery(const Bakery& bakery) {

    QCommandLinkButton* button = new QCommandLinkButton();

    button->setText(bakery.get_name());
    button->setIcon(QIcon(Ui::SHOP_ICON));

    // Used to know which bakery is selected
    button->setAccessibleName(QString::number(bakery.get_id()));

    ui->bakeriesView->layout()->addWidget(button);
    ui->bakeriesView->layout()->addWidget(createHorizontalLine());

    connect(button, SIGNAL(clicked()), this, SLOT(bakeryButtonClicked()));
}

/**
 * Custom slot which all the created bakeries buttons are connected to. Since this slot
 * is ONLY used to the bakeries button the sender object is casted to a QCommandLinkButton
 * (inherited by the bakeries button) then the button accessible name is extracted, in which
 * the bakery id was encapsulated. Then a "bakerySelected" signal is emmited with the selected
 * bakery id.
 */
void SelectWindow::bakeryButtonClicked() {

    QCommandLinkButton* button = dynamic_cast<QCommandLinkButton*>(sender());

    emit bakerySelected(button->accessibleName().toInt());
}

/**
 * Creates a Horizontal line used to separete bakeries buttons.
 */
QWidget* SelectWindow::createHorizontalLine() {

    QWidget *hLine = new QWidget;
    hLine->setFixedHeight(2);
    hLine->setFixedWidth(ui->scrollArea->width() - MARGIN);
    hLine->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    hLine->setStyleSheet(QString("background-color: #c0c0c0;"));

    return hLine;
}

/**
 * @param url The website which is going to be displayed. It must contain https:// or http://
 * Displays a given website with JavaScript enabled. Note: OpenSSL needs to be installed in the client,
 * otherwise some web pages will block the access and redirect the request to an http.
 */
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
