cmake_minimum_required(VERSION 3.5)
project(Minopoly VERSION 0.1 LANGUAGES CXX)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_library(
        game-state
        src/GameState.cpp
        include/game-state/GameState.h
        include/Board.h
        include/Board.cpp
        include/Property.h
        include/Game.cpp
        include/Player.cpp
)

target_include_directories(game-state PUBLIC include)