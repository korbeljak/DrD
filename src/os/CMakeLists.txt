cmake_minimum_required(VERSION 2.8)
get_filename_component(ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../.." ABSOLUTE)
list(APPEND CMAKE_MODULE_PATH ${ROOT_DIR}/cmake)
list(REMOVE_DUPLICATES CMAKE_MODULE_PATH)


project(DrD_os C)
include(Environment)

set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/oscommon.c
)

set(INC
    ${ROOT_DIR}/include/drd/os/os.h
)

if ("${CMAKE_SYSTEM_NAME}" MATCHES "Linux")
    list(APPEND SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/linux/os.c
    )
elseif ("${CMAKE_SYSTEM_NAME}" MATCHES "Windows")
    list(APPEND SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/windows/os.c
    )
else ()
    message(SEND_ERROR "Unknown platform. Known: Linux, Windows")
endif() 

set(INC_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${ROOT_DIR}/include
    ${CMAKE_BINARY_DIR}/include
)

include_directories(${INC_DIRS})

add_library(${PROJECT_NAME} STATIC ${SRC})
