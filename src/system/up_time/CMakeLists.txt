set(INCLUDE_PATH ${CMAKE_SOURCE_DIR}/include)

add_library(up_time_service_lib "")

target_include_directories(
    up_time_service_lib 
    PUBLIC
        ${INCLUDE_PATH})

target_sources(
    up_time_service_lib 
    PRIVATE
        up_time_service.cpp
        ${INCLUDE_PATH}/system/up_time/up_time_service.h)