cmake_minimum_required(VERSION 3.13)
project(monitor)

add_executable(${PROJECT_NAME})
add_subdirectory(src)

set_property(TARGET monitor PROPERTY CXX_STANDARD 17)

target_compile_options(monitor PRIVATE -Wall -Wextra)
