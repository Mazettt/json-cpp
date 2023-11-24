cmake_minimum_required(VERSION 3.20)
project(LibJson CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/Array.cpp
    src/Bool.cpp
    src/Float.cpp
    src/Int.cpp
    src/Json.cpp
    src/Null.cpp
    src/Object.cpp
    src/Parser.cpp
    src/String.cpp
)

add_library(json SHARED ${SOURCES})

set_target_properties(json PROPERTIES OUTPUT_NAME "json")

if(WIN32)
    set_target_properties(json PROPERTIES SUFFIX ".dll")
endif()

target_include_directories(json PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
