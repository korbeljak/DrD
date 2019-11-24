cmake_minimum_required(VERSION 2.8)
get_filename_component(ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../.." ABSOLUTE)
list(APPEND CMAKE_MODULE_PATH ${ROOT_DIR}/cmake)
list(REMOVE_DUPLICATES CMAKE_MODULE_PATH)

project(DrD_android C)

set(SRC
)

set(CMAKE_BUILD_TYPE "Debug")

set(INC_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${ROOT_DIR}/include
    ${CMAKE_BINARY_DIR}/include
)

include_directories(${INC_DIRS})

add_library(${PROJECT_NAME} STATIC ${SRC})
