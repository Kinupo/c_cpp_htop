#ifndef NCURSES_DISPLAY_H
#define NCURSES_DISPLAY_H

#include <curses.h>

#include <chrono>
#include <string>
#include <thread>
#include <vector>

#include "format.h"
#include "process.h"
#include "system.h"

namespace NCursesDisplay {
void Display(System& system);
void DisplaySystem(System& system, WINDOW* window);
void DisplayProcesses(std::vector<Process>& processes, WINDOW* window, int n);
std::string ProgressBar(float percent);
};  // namespace NCursesDisplay

#endif