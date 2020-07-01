set(INCLUDE_PATH ${CMAKE_SOURCE_DIR}/include)
set(THREADS_PREFER_PTHREAD_FLAG ON)

target_include_directories(
    monitor 
    PUBLIC
        ${INCLUDE_PATH})

target_sources(
    monitor 
    PRIVATE
        main.cpp
        ${INCLUDE_PATH}/system/monitor_factory.h
        ${INCLUDE_PATH}/system/status/system_monitor.h
        ${INCLUDE_PATH}/terminal_ui/terminal_ui.h
        )

add_subdirectory(file)
add_subdirectory(system)
add_subdirectory(terminal_ui)

find_library(CURSES_LIBRARIES curses)
find_package(Threads REQUIRED)
target_link_libraries(
    monitor 
        ${CURSES_LIBRARIES}
        Threads::Threads
        terminal_lib
        system_monitor_lib
        file_reader_lib
)