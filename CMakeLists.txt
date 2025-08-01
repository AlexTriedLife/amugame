cmake_minimum_required(VERSION 3.31)
project(amugame)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_custom_target(copy_assets ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_BINARY_DIR}/assets
)

set(CMAKE_PREFIX_PATH "C:/Libraries/SDL3" "C:/Libraries/SDL3_ttf" "C:/Libraries/SDL3_image")
find_package(SDL3 REQUIRED CONFIG COMPONENTS SDL3)
find_package(SDL3_ttf REQUIRED CONFIG)
find_package(SDL3_image REQUIRED CONFIG)
set(SOURCES
        src/main.cpp
        src/ui/button.cpp
        src/ui/text_button.cpp
        src/ui/label.cpp
        src/render/triangle.cpp
        src/input/input_manager.cpp
)
add_executable(amugame ${SOURCES})
target_include_directories(amugame PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${SDL3_INCLUDE_DIRS}
)
target_link_libraries(amugame PRIVATE
        SDL3::SDL3
        SDL3_ttf::SDL3_ttf
        SDL3_image::SDL3_image
)
add_dependencies(amugame copy_assets)


