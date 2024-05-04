cmake_minimum_required(VERSION 3.27)
project(TBG)

set(CMAKE_CXX_STANDARD 17)

IF (WIN32)
    set(SFML_DIR "C:/Program Files/JetBrains/SFML-2.6.1/lib/cmake/SFML")
    set(SFML_STATIC_LIBRARIES TRUE)
ENDIF()

find_package(SFML 2.6 COMPONENTS graphics audio window REQUIRED)

add_executable(TBG main.cpp
        Unit.cpp
        Game.cpp
        UserUnit.cpp
        PcUnit.cpp
        BackGround.cpp
)

target_link_libraries(TBG sfml-graphics)