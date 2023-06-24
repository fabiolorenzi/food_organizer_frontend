cmake_minimum_required(VERSION 3.1)
project(food_organizer VERSION 1.0.0 LANGUAGES CXX)

set(Qt5_DIR /usr/lib/x86_64-linux-gnu/cmake/Qt5)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(
    food_organizer
    src/main.cpp
    src/forms/MainWindow.ui
    src/classes/MainWindow.cpp
    #resource.qrc
)
set_target_properties(
    food_organizer
    PROPERTIES
        OUTPUT_NAME "food_organizer"
        SUFFIX ".exe"
)

target_link_libraries(food_organizer Qt5::Widgets)