cmake_minimum_required(VERSION 3.16)

project(hrai-space-desktop VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Network REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Network REQUIRED)

set(PROJECT_SOURCES
        Main.cpp
        Main_Window.cpp
        Main_Window.h
        Top_Bar.h
        Top_Bar.cpp
        Library_Page.h
        Library_Page.cpp
        Game_Tile.h Game_Tile.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(hrai-space-desktop
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        resources/resources.qrc
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET hrai-space-desktop APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
else()
    if(ANDROID)
        add_library(hrai-space-desktop SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(hrai-space-desktop
            ${PROJECT_SOURCES}
            resources/resources.qrc
        )
    endif()
endif()

target_link_libraries(hrai-space-desktop PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(hrai-space-desktop PRIVATE Qt${QT_VERSION_MAJOR}::Network)

set_target_properties(hrai-space-desktop PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(hrai-space-desktop)
endif()
