cmake_minimum_required(VERSION 2.8)
get_filename_component(ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../.." ABSOLUTE)
list(APPEND CMAKE_MODULE_PATH ${ROOT_DIR}/cmake)
list(REMOVE_DUPLICATES CMAKE_MODULE_PATH)

project(DrD_wxwidgets C CXX)

set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DrdGuiApp.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DrdGuiFrame.cpp
)

set(INC
    ${CMAKE_CURRENT_SOURCE_DIR}/DrdGuiApp.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DrdGuiFrame.hpp
)

set(CMAKE_BUILD_TYPE "Debug")

set(INC_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${ROOT_DIR}/include
    ${CMAKE_BINARY_DIR}/include
    ${ROOT_DIR}/../git/wxWidgets/include
)

include_directories(${INC_DIRS})

add_subdirectory(${ROOT_DIR}/../git/wxWidgets wxWidgets)

# HAXXS
add_definitions(-D_FILE_OFFSET_BITS=64
-DWXUSINGDLL
#-D__WXGTK__
-D__WXGTK3__
-pthread
-lwx_gtk3u_xrc-3.0
-lwx_gtk3u_html-3.0
-lwx_gtk3u_qa-3.0
-lwx_gtk3u_adv-3.0
-lwx_gtk3u_core-3.0
-lwx_baseu_xml-3.0
-lwx_baseu_net-3.0
-lwx_baseu-3.0)

include_directories(
#/usr/lib/wx/include/gtk2-unicode-3.0
#/usr/include/wx-3.0
${CMAKE_BINARY_DIR}/lib/wx/include/gtk3-unicode-static-3.1)

add_library(${PROJECT_NAME} STATIC ${SRC} ${INC})


target_link_libraries(${PROJECT_NAME} base core net)
