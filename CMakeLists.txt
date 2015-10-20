cmake_minimum_required(VERSION 2.8)
project(Bollo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_AUTOMOC ON)
# cmake_policy(SET CMP0043 NEW)

set(SOURCE_FILES src/main.cpp src/core/classes/bakery.cpp src/core/classes/bakery.h src/core/build.h src/logger/logger.cpp src/logger/logger.h src/io/sql.cpp src/io/sql.h src/core/bollo.cpp src/core/bollo.h src/core/classes/person.cpp src/core/classes/person.h src/ui/logindialog.cpp src/ui/logindialog.h src/ui/ui_headers/ui_logindialog.h src/core/classes/baker.cpp src/core/classes/baker.h src/core/classes/yeast.cpp src/core/classes/yeast.h src/ui/mainwindow.cpp src/ui/mainwindow.h src/ui/ui_headers/ui_mainwindow.h src/ui/menuactionmanager.cpp src/ui/menuactionmanager.h src/ui/popup.cpp src/ui/popup.h src/ui/ui_headers/ui_popup.h src/ui/telegramcpanel.cpp src/ui/telegramcpanel.h src/ui/ui_headers/ui_telegramcpanel.h src/ui/themes.cpp src/ui/themes.h)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Sql REQUIRED)

# QT .qrc file crap
set(RESOURCE ${CMAKE_SOURCE_DIR}/src/ui/resources.qrc)
qt5_add_resources(RESOURCE_ADDED ${RESOURCE})

add_executable(Bollo ${SOURCE_FILES} ${RESOURCE_ADDED})

qt5_use_modules(Bollo Core Widgets Gui Network Sql)
