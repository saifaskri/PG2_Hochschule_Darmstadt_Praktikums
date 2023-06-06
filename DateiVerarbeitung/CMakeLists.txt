cmake_minimum_required(VERSION 3.5)

project(DateiVerarbeitung LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DateiVerarbeitung main.cpp dateiverarbeitung.h dateiverarbeitung.cpp)

install(TARGETS DateiVerarbeitung
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
