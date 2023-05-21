cmake_minimum_required(VERSION 3.5)

project(abdrahmen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(abdrahmen main.cpp)

install(TARGETS abdrahmen
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
