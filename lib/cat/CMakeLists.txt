cmake_minimum_required(VERSION 3.0)
project(Cat)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)

file(GLOB HEADERS "*.h*")
file(GLOB SOURCES "*.c*")

add_library(${PROJECT_NAME} SHARED ${HEADERS} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)