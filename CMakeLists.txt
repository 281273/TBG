cmake_minimum_required(VERSION 3.27)
project(TBG)

set(CMAKE_CXX_STANDARD 17)

add_executable(TBG main.cpp
        Unit.cpp
        Game.cpp)
