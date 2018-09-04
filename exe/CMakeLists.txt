cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../lib)

file(GLOB SOURCES "*.c*")
file(GLOB HEADERS "*.h*")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} )