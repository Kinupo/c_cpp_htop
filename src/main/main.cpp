// #include "system/display/ncurses_display.h"
// #include "system/status/system.h"
#include <curses.h>
#include <thread>
#include <chrono>

int main() {

  initscr();      // start ncurses
  noecho();       // do not print input values
  cbreak();       // terminate ncurses on ctrl + c
  start_color();  // enable color
  curs_set(0);    // hide cursor

  int terminal_width{getmaxx(stdscr)};
  int number_of_terminal_lines{getmaxy(stdscr)};
  int number_of_data_rows{7};
  int numberOfBorderRows{2};
  int numberOfHeaderRows{1};
  int numberOfDataRows{10};
  int window_buffer{1};

  WINDOW* system_window = newwin(
    number_of_data_rows + numberOfBorderRows, 
    terminal_width - 1, //-1: 0 index adjustment
    0, 
    0);
  int top_of_next_window{system_window->_maxy +1};
  WINDOW* process_window =
      newwin(
        number_of_terminal_lines - system_window->_maxy -(1 + window_buffer) , //height; -1: 0 index adjustment
        terminal_width - 1, //width; -1: 0 index adjustment
        top_of_next_window, //y_pos top left
        0); //x_pos top left

  while(1){
      box(system_window, 0, 0);
    box(process_window, 0, 0);
    mvwprintw(system_window, 0, 6, "System");
    wnoutrefresh(system_window);
    wnoutrefresh(process_window);
    doupdate();
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  return 0;
}