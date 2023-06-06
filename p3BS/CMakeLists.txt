cmake_minimum_required(VERSION 3.5)

project(p3BS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(p3BS main.cpp cpu.cpp cpu.h qeue.h)

install(TARGETS p3BS
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
