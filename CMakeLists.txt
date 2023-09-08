cmake_minimum_required(VERSION 3.10)
project(editor)

set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED)
include_directories(
    ${SDL2_INCLUDE_DIRS} 
    include
    )

set(SOURCE_FILES
    src/main.cpp
    src/tile_file.cpp
    src/crop_component.cpp
    src/tile_selector.cpp
    src/mouse_selector_component.cpp
)

add_executable(editor ${SOURCE_FILES})

target_link_libraries(editor sfml-graphics sfml-window sfml-system)
