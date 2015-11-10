cmake_minimum_required(VERSION 2.8)
project(Bollo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(CMAKE_AUTOMOC ON)
# cmake_policy(SET CMP0043 NEW)

set(SOURCE_FILES src/main.cpp src/core/classes/bakery.cpp src/core/classes/bakery.h
        src/core/build.h src/logger/logger.cpp src/logger/logger.h
        src/core/bollo.cpp src/core/bollo.h src/core/classes/person.cpp src/core/classes/person.h
        src/ui/logindialog.cpp src/ui/logindialog.h src/ui/ui_headers/ui_logindialog.h src/core/classes/baker.cpp
        src/core/classes/baker.h src/core/classes/yeast.cpp src/core/classes/yeast.h src/ui/mainwindow.cpp
        src/ui/mainwindow.h src/ui/ui_headers/ui_mainwindow.h src/ui/menuactionmanager.cpp src/ui/menuactionmanager.h
        src/ui/popup.cpp src/ui/popup.h src/ui/ui_headers/ui_popup.h src/ui/telegramcpanel.cpp src/ui/telegramcpanel.h
        src/ui/ui_headers/ui_telegramcpanel.h src/ui/themes.cpp src/ui/themes.h src/core/classes/ministry.cpp
        src/core/classes/ministry.h src/io/http.cpp src/io/http.h src/logger/easylogging++.h src/ui/assets.h src/ui/bakeryselect.cpp
        src/ui/bakeryselect.h src/ui/ui_headers/ui_bakeryselect.h src/ui/preferencespanel.cpp src/ui/preferencespanel.h
        src/ui/ui_headers/ui_preferencespanel.h src/io/handler.h src/core/bollo_constants.h src/core/bollo_constants.cpp
        src/core/classes/logbook.cpp src/core/classes/logbook.h src/ui/ui_headers/ui_logbookdialog.h src/ui/logbookdialog.cpp
        src/ui/logbookdialog.h src/ui/selectpane.cpp src/ui/selectpane.h src/ui/ui_headers/ui_selectpane.h
        src/ui/bakeryedit.cpp src/ui/bakeryedit.h src/ui/ui_headers/ui_bakeryedit.h src/ui/about.cpp src/ui/about.h
        src/ui/ui_headers/ui_about.h)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Sql REQUIRED)
find_package(Qt5WebKit REQUIRED)


# QT .qrc file crap
set(RESOURCE ${CMAKE_SOURCE_DIR}/src/ui/resources.qrc)
qt5_add_resources(RESOURCE_ADDED ${RESOURCE})

add_executable(Bollo ${SOURCE_FILES} ${RESOURCE_ADDED})

qt5_use_modules(Bollo Core Widgets Gui Network Sql WebKitWidgets)
