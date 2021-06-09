set(INCLUDE_PATH ${CMAKE_SOURCE_DIR}/include)

add_library(parser_lib "")

target_include_directories(
    parser_lib 
    PUBLIC
        ${INCLUDE_PATH})

target_sources(
    parser_lib 
    PRIVATE
        delimited_parser.cpp
        ${INCLUDE_PATH}/parser/delimited_parser.h
        )