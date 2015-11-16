//
// Created by ricardo on 10/11/15.
//

#ifndef BOLLO_SETTINGS_H
#define BOLLO_SETTINGS_H

#include <QtCore/qsettings.h>
#include <QtCore/qstring.h>
#include <QtCore/qdir.h>

#include "../core/bollo_constants.h"
#include "../logger/easylogging++.h"

QString config_file_path();

void init_settings(void);

void load_default_settings(void);

void load_settings(void);

void set_setting(const QString&, const QString&, const QVariant&);

QVariant get_setting(const QString&, const QString&);

#endif //BOLLO_SETTINGS_H
