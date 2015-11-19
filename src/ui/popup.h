#ifndef POPUP_H
#define POPUP_H

#include <string>
#include "../logger/easylogging++.h"

using namespace std;

void sendNotification(string, string, string);

void sendInfoNotification(string, string);

void sendWarningNotification(string, string);

void sendQuestionNotification(string, string);

#endif // POPUP_H
