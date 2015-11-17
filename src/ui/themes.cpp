/**
 * @author Daniel Aguilar
 *
 * Color themes that can be applied to the GUI.
 */
#include <QApplication>
#include <QStyleFactory>
#include <QPalette>

#include "themes.h"
#include "mainwindow.h"

/**
 * @brief Ui::setDarkTheme Modern GUI dark theme
 * Set the GUI theme to a modern dark theme for
 * Creates a custom palette which customize all the
 * main GUI components (buttons, links, text, etc).
 * Some CSS is used to set the tooltips style.
 */
void Ui::setDarkTheme() {

    qApp->setStyle(QStyleFactory::create("Fusion"));

    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53,53,53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25,25,25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53,53,53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));

    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    qApp->setPalette(darkPalette);

    qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");
    LOG(DEBUG) << "Changing UI theme to: DARK";
}

/**
 * @brief Ui::setLightTheme Default theme
 * Reverts all the changes made by the dark theme
 * by setting the QT Fusion style and reseting
 * the stylesheet.
 */
void Ui::setLightTheme() {

    QMainWindow* dummy = new QMainWindow();
    qApp->setStyle(QStyleFactory::create("Fusion"));
    qApp->setPalette(dummy->style()->standardPalette());
    qApp->setStyleSheet("");

    dummy->deleteLater();

    LOG(DEBUG) << "Changing UI theme to: LIGHT";
}
