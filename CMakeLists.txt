cmake_minimum_required(VERSION 3.16)
project(monitor)

add_executable(${PROJECT_NAME})
add_subdirectory(src/main)

set_property(TARGET monitor PROPERTY CXX_STANDARD 17)

# TODO: Run -Werror in CI.
target_compile_options(monitor PRIVATE -Wall -Wextra)
