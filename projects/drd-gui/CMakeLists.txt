cmake_minimum_required(VERSION 2.8)
get_filename_component(ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../.." ABSOLUTE)
list(APPEND CMAKE_MODULE_PATH ${ROOT_DIR}/cmake)
list(REMOVE_DUPLICATES CMAKE_MODULE_PATH)

project(DrD-gui C CXX)

set(SRC
${CMAKE_CURRENT_SOURCE_DIR}/main.c
)

set(CMAKE_BUILD_TYPE "Debug")

set(INC_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${ROOT_DIR}/include
    ${CMAKE_BINARY_DIR}/include
)

include_directories(${INC_DIRS})


add_subdirectory(${ROOT_DIR}/src DrD)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} DrD_os DrD_roll DrD_wxwidgets)
