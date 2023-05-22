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
	ui/Main_Window.h ui/Main_Window.cpp
	ui/Top_Bar.h ui/Top_Bar.cpp
	ui/Library_Page.h ui/Library_Page.cpp
	ui/Game_Tile.h ui/Game_Tile.cpp
	ui/Popup.h ui/Popup.cpp
	ui/Login_Popup.h ui/Login_Popup.cpp
	ui/Game_Page.h ui/Game_Page.cpp
	ui/Picture_Widget.h ui/Picture_Widget.cpp
	data/Game.h data/Game.cpp
	data/User.h data/User.cpp
	data/Unzipper.h data/Unzipper.cpp
	network/Network_Manager.h network/Network_Manager.cpp
	network/Web_Downloader.h network/Web_Downloader.cpp
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
	    resources/project.rc
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

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "Hrai-Space-${CMAKE_SYSTEM_PROCESSOR}")
