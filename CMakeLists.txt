cmake_minimum_required(VERSION 3.1.0)

project(druid)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Test REQUIRED)
find_package(Qwt REQUIRED)
find_package(Bard REQUIRED)

add_subdirectory(src)
