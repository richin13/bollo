#include <QtWidgets/qmessagebox.h>
#include "src/core/build.h"
#include "src/logger/logger.h"
#include "src/core/bollo.h"
#include "src/ui/logindialog.h"

using namespace bollo;

int main(int argc, char** argv) {
//    QApplication application(argc, argv);
    BolloApp app(argc, argv);

    cout << "Hello, World! I am Bollo\n";
    cout << "This... is... just... the beginning\n";
    cout << "Expect us!" << endl;

//    _log.bakery(1) << "Logging in PostgresSQL!";
//    QString pw = "abc123";
//    QByteArray byteArray = pw.toUtf8();
//    int id = query::login(QString("richin13"), byteArray);
//    cout << endl << id << endl;
//    _log.bakery(bakery->get_id()) << "Logging!";

    if(!BolloApp::success_connection) {
        QMessageBox::critical(nullptr, "Unable to connect to the database server",
                              "An error occurred while trying to reach the PosgreSQL server");
    } else {

    }

    LoginDialog loginDialog;
    loginDialog.show();

//    return application.exec();
    return app.exec();
//    return EXIT_SUCCESS;
}