#include "chartsbrowser.h"
#include "ui_headers/ui_chartsBrowser.h"

ChartsBrowser::ChartsBrowser(QWidget* parent) : QDialog(parent),
                                                ui(new Ui::ChartsBrowser) {

    ui->setupUi(this);
    settings();

    fillBakeriesList();

    // Load general charts by default
    loadPage(0);
}

ChartsBrowser::~ChartsBrowser() {

    delete ui;
}

/**
 * Apply some settings that can be applied with designer.
 */
void ChartsBrowser::settings() {

    // Each time a bakery is selected, load its charts web page from server
    connect(ui->bakeriesList, SIGNAL(activated(int)), this, SLOT(loadPage(int)));

    // Add web page viewer
    viewer = new QWebView();
    QWebPage* page = viewer->page();
    QWebSettings* settings = page->settings();

    settings->setAttribute(QWebSettings::JavascriptEnabled, true);
    settings->setAttribute(QWebSettings::PluginsEnabled, true);
    settings->setAttribute(QWebSettings::PrivateBrowsingEnabled, true);

    ui->scrollArea->setWidget(viewer);
}

/**
 * @param bakeryIndex Bakery index in the combo box, which is the same in the bakery list in BolloApp
 *
 * The website which is going to be displayed. It must contain https:// or http://
 * The webisite is displayed with JavaScript enabled. Note: OpenSSL needs to be installed in the client,
 * otherwise some web pages will block the access and redirect the request to an http.
 */
void ChartsBrowser::loadPage(int bakeryIndex) {

    if(bakeryIndex == 0) {
        viewer->load(Constants::CHARTS_URL);
    } else {
        LOG(INFO) << "Displaying charts for bakery: " + to_string(bakeryIndex);
        viewer->load(buildUrl(BolloApp::get().bakeries.at((ulong) bakeryIndex - 1)->get_id()));
    }

    viewer->setFocus();
    viewer->show();
}

/**
 * Build the url need to acces de charts for each bakery in the server.
 */
QUrl ChartsBrowser::buildUrl(int bakeryId) {
    return Constants::API_HOST + "/?charts=" + QString::number(bakeryId) + "&thisTextMustBeSuperSecret!__-___";
}

/**
 * Fill the bakeries combo box, used to select the bakery and display its chart.
 */
void ChartsBrowser::fillBakeriesList() {

    int listSize = (int) BolloApp::get().bakeries.size();

    if(listSize != 0) {

        for(int i = 0; i < listSize; ++i) {

            ui->bakeriesList->addItem(BolloApp::get().bakeries.at(i)->get_name());
        }
    }
}