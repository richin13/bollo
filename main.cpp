#include "src/core/build.h"
#include "src/logger/logger.h"

using namespace bollo;

int main() {
    cout << "Hello, World! I am Bollo\n";
    cout << "This... is... just... the beginning\n";
    cout << "Expect us!" << endl;

    _log << "This is the first log entry";

    return EXIT_SUCCESS;
}