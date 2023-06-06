cmake_minimum_required(VERSION 3.5)

project(FileConverter LANGUAGES C)

add_executable(FileConverter main.c)

install(TARGETS FileConverter
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
