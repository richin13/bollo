#include "popup.h"
#include "../logger/easylogging++.h"

using namespace std;

void showPopup(std::string title, std::string message) {

    string command = "notify-send '" + title + "' '" + message + "' --icon=dialog-information";

    int returnCode = system(command.c_str());

    if (returnCode < 0) {

        LOG(WARNING) << "An error ocurred while showing event notification";
    }
}
