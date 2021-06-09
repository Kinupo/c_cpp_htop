set(INCLUDE_PATH ${CMAKE_SOURCE_DIR}/include)

add_library(processes_monitor_lib "")

target_include_directories(
    processes_monitor_lib 
    PUBLIC
        ${INCLUDE_PATH})

target_sources(
    processes_monitor_lib 
    PRIVATE
        process_status.cpp
        processes_status.cpp
        processes_monitor.cpp
        ${INCLUDE_PATH}/system/component/process/process_status.h
        ${INCLUDE_PATH}/system/component/process/processes_status.h
        ${INCLUDE_PATH}/system/component/process/processes_monitor.h
)

target_link_libraries(
    processes_monitor_lib 
        parser_lib
        file_reader_lib
)