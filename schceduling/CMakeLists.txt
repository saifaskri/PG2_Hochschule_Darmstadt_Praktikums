cmake_minimum_required(VERSION 3.5)

project(schceduling LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(schceduling main.cpp)

install(TARGETS schceduling
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
