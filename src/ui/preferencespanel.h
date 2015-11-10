#ifndef PREFERENCESPANEL_H
#define PREFERENCESPANEL_H

#include <QDialog>

#include "ui_headers/ui_preferencespanel.h"
#include "../io/settings.h"

namespace Ui {
class PreferencesPanel;
}

class PreferencesPanel : public QDialog
{
    Q_OBJECT

public:
    explicit PreferencesPanel(QWidget *parent = 0);
    ~PreferencesPanel();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_badDoughCB_toggled(bool checked);

    void networkingChanged();
    void bakerySettingsChanged();


private:
    Ui::PreferencesPanel *ui;
    bool networkingHasChanged;
    bool bakerySettingsHasChanged;

    void fillSettingsValue();
    void connectEventChangeManagers();
    void writePreferencesToFile();
};

#endif // PREFERENCESPANEL_H
