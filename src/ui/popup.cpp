/**
 * @author Daniel Aguilar, Ricardo Madriz
 *
 * Simple wrapper used to make notifications to the user with libnotify library.
 * A system call is made to the system, since this app is linux only we used this
 * method in order to use less dependencies, since the libnotify library for C++
 * it's not installed by default in most linux distros.
 */
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