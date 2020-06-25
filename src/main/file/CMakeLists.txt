set(INCLUDE_PATH ${CMAKE_SOURCE_DIR}/include)

add_library(fileLib "")

target_include_directories(
    fileLib 
    PUBLIC
        ${INCLUDE_PATH})

target_sources(
    fileLib 
    PRIVATE
        delimited_file_reader.cpp
        property_file_reader.cpp
        linux_parser.cpp
        ${INCLUDE_PATH}/file/linux_parser.h)
