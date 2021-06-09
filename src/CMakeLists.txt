set(CMAKE_CXX_STANDARD 17)
set(INCLUDE_PATH ${CMAKE_SOURCE_DIR}/include)
set(THREADS_PREFER_PTHREAD_FLAG ON)

add_subdirectory(system)
add_subdirectory(parser)
add_subdirectory(file_reader)

target_include_directories(
    monitor 
    PUBLIC
        ${INCLUDE_PATH})

target_sources(
    monitor 
    PRIVATE
        main.cpp
        format.cpp 
        ncurses_display.cpp 
        process.cpp 
        system.cpp 
        processor.cpp 
        ${INCLUDE_PATH}/format.h
        ${INCLUDE_PATH}/ncurses_display.h 
        ${INCLUDE_PATH}/process.h 
        ${INCLUDE_PATH}/system.h 
        ${INCLUDE_PATH}/processor.h
        )

find_library(CURSES_LIBRARIES curses)
find_package(Threads REQUIRED)
target_link_libraries(
    monitor 
        ${CURSES_LIBRARIES}
        Threads::Threads
        system_monitor_lib
)