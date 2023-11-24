cmake_minimum_required(VERSION 3.20)
project(MyApp CXX)

add_subdirectory(.. json-cpp)

set(APP_SOURCES
    Main.cpp
)

add_executable(my_app ${APP_SOURCES})

target_link_libraries(my_app PRIVATE json)
