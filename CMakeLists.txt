cmake_minimum_required(VERSION 3.5)

project(Minopoly VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Minopoly)
add_subdirectory(game-state)
add_subdirectory(third_party/nlohmann_json) # Librairie JSON