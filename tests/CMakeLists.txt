cmake_minimum_required(VERSION 3.5)

project(tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tests main.cpp)

install(TARGETS tests
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
