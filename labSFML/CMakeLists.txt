cmake_minimum_required(VERSION 3.17)
project(labSFML)

set(CMAKE_CXX_STANDARD 14)

add_executable(labSFML labSFML.cpp)

target_link_libraries(labSFML sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)