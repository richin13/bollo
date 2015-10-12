#include "src/core/build.h"
#include "src/logger/logger.h"
#include "src/core/bollo.h"

using namespace bollo;

int main(int argc, char** argv) {
    BolloApp app(argc, argv);

    cout << "Hello, World! I am Bollo\n";
    cout << "This... is... just... the beginning\n";
    cout << "Expect us!" << endl;

    _log.bakery(1) << "Logging in PostgreSQL!";
//    _log.bakery(bakery->get_id()) << "Logging!";
    return EXIT_SUCCESS;
}