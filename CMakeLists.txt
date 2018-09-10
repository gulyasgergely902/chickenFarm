cmake_minimum_required(VERSION 3.1)
project(chickenFarm)

set(CMAKE_CXX_STANDARD 11)

#set(QT_DIR /home/dsindahouse/Qt5.11.1/5.11.1/gcc_64)
set(QT_DIR /home/gulyas/Qt/5.11.1/gcc_64)

find_package(Qt5Core REQUIRED HINTS ${QT_DIR})

add_executable(chickenFarm main.cpp Farm.cpp Farm.h Utils.cpp Utils.h Chicken.cpp Chicken.h)

target_link_libraries(chickenFarm Qt5::Core)