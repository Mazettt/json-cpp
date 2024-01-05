cmake_minimum_required(VERSION 3.20)
project(LibJson CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(SOURCES
    src/types/Array.cpp
    src/types/Bool.cpp
    src/types/Float.cpp
    src/types/Int.cpp
    src/types/Null.cpp
    src/types/Object.cpp
    src/types/String.cpp
    src/Json.cpp
    src/Parser.cpp
)

add_library(json SHARED ${SOURCES})

set_target_properties(json PROPERTIES OUTPUT_NAME "json")

if(WIN32)
    set_target_properties(json PROPERTIES SUFFIX ".dll")
endif()

target_include_directories(json PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
