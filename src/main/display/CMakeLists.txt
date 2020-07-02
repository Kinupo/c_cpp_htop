set(INCLUDE_PATH ${CMAKE_SOURCE_DIR}/include)

add_library(display_lib "")

target_include_directories(
    display_lib 
    PUBLIC
        ${INCLUDE_PATH})

target_sources(
    display_lib 
    PRIVATE
        delimited_file_reader.cpp
        property_file_reader.cpp
        ${INCLUDE_PATH}/file/delimited_file_reader.h
        ${INCLUDE_PATH}/file/property_file_reader.h)