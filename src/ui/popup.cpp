#include "popup.h"

void showPopup(string title, string msg, string icon) {
    string cmd = "notify-send '" + title + "' '" + msg + "' --icon=" + icon;

    if(system(cmd.c_str())) {
        LOG(WARNING) << "An error ocurred while showing the event notification";
    }
}

void showInfoPopup(string title, string msg) {
    showPopup(title, msg, "dialog-information");
}

void showWarningPopup(string title, string msg) {
    showPopup(title, msg, "dialog-warning");
}

void showQuestionPopup(string title, string msg) {
    showPopup(title, msg, "dialog-question");
}