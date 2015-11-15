#ifndef POPUP_H
#define POPUP_H

#include <string>
#include "../logger/easylogging++.h"

using namespace std;

void showPopup(string, string, string);

void showInfoPopup(string, string);

void showWarningPopup(string, string);

void showQuestionPopup(string, string);

#endif // POPUP_H
