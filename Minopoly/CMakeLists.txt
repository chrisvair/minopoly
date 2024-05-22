cmake_minimum_required(VERSION 3.5)
project(Minopoly VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        src/main.cpp
        src/mainwindow.cpp
        src/mainwindow.h
        src/mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
qt_add_executable(Minopoly
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
)
else()
        add_executable(Minopoly
            ${PROJECT_SOURCES}
        )
endif()

target_include_directories(Minopoly PRIVATE src)
target_include_directories(Minopoly PRIVATE forms)

target_link_libraries(Minopoly PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(Minopoly PRIVATE game-state)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Minopoly)
endif()
set_target_properties(Minopoly PROPERTIES
        ${BUNDLE_ID_OPTION}
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
qt_finalize_executable(Minopoly)
endif()