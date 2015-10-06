cmake_minimum_required(VERSION 2.8)
project(Bollo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_AUTOMOC ON)

set(SOURCE_FILES main.cpp src/core/bakery.cpp src/core/bakery.h src/core/build.h)
add_executable(Bollo ${SOURCE_FILES})

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)

qt5_use_modules(Bollo Core Widgets Gui)