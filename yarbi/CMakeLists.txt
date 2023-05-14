cmake_minimum_required(VERSION 3.5)

project(yarbi LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(yarbi main.cpp)

install(TARGETS yarbi
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
