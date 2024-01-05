cmake_minimum_required(VERSION 3.20)
project(MyTest CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_subdirectory(.. json-cpp)

set(APP_SOURCES
    Main.cpp
)

add_executable(json_tests ${APP_SOURCES})

target_link_libraries(json_tests PRIVATE json)
