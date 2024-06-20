cmake_minimum_required(VERSION 3.5)
project(Minopoly VERSION 0.1 LANGUAGES CXX)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_library(
        game-state
        include/Board.h
        include/Board.cpp
        include/Property.h
        include/Property.cpp

        include/Player.cpp
        include/Player.h
        include/Property.cpp
        include/Game.cpp
        src/JsonSerializer.h
        include/JsonSerializer.cpp
        include/Card.cpp

)

target_include_directories(game-state PUBLIC include)
target_link_libraries(game-state PUBLIC nlohmann_json::nlohmann_json)
