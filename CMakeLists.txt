cmake_minimum_required(VERSION 3.31)
project(webServer)

set(CMAKE_CXX_STANDARD 20)

add_executable(webServer main.cpp
        server.h
        menu_txt.h
)
