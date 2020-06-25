find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS} include)/display)

add_library(displayLib "format.cpp")

file("src/main/display/format.cpp")
file("src/main/display/ncurses_display.cpp")