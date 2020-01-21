cmake_minimum_required(VERSION 3.10)
project(THREAD LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
find_package(Threads REQUIRED)

file(GLOB_RECURSE cpu_source_files "${PROJECT_SOURCE_DIR}/src/*.cpp")

include_directories("${PROJECT_SOURCE_DIR}/include/")
add_library(${PROJECT_NAME} STATIC ${cpu_source_files})

set_target_properties(${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})

add_executable(THREAD_TEST ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(THREAD_TEST ${PROJECT_NAME})
