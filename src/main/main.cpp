// #include "system/display/ncurses_display.h"
// #include "system/status/system.h"
#include "system/monitor_factory.h"
#include "terminal_ui/terminal_ui.h"

#include <curses.h>
#include <thread>
#include <chrono>
#include <memory>

#include <map>

std::map<std::string, WINDOW*> CreateWindows(TerminalUi &terminal_ui){
  
  int number_of_data_rows{7};
  int numberOfBorderRows{2};

  auto system_window = terminal_ui.CreateWindow(
      number_of_data_rows + numberOfBorderRows, 
      -1);
  auto process_window = terminal_ui.CreateWindowBelow(
    system_window, 
    -1, 
    -1);

  std::map<std::string, WINDOW*> windows;
  windows.insert(std::pair<std::string, WINDOW*>{"Process", process_window});
  windows.insert(std::pair<std::string, WINDOW*>{"System", system_window});
  return windows;
}

std::shared_ptr<SystemMonitor> BuildSystemMonitor(){
  MonitorFactory monitorFactory;
  return monitorFactory.BuildSystemMonitor();
}

std::unique_ptr<TerminalUi> BuildTerminalUi(){
  return std::unique_ptr<TerminalUi>(new TerminalUi());
}

int main() {

  auto system_monitor = BuildSystemMonitor();
  auto system_status = system_monitor->Status();

  auto terminal_ui = BuildTerminalUi();
  terminal_ui->InitilizeTerminal();

  auto windows = CreateWindows(*terminal_ui);

  box(windows.find("System")->second, 0, 0);
  mvwprintw(windows.find("System")->second, 0, 6, "System");
  
  box(windows.find("Process")->second, 0, 0);
  
  while(1){
    mvwprintw(windows.find("System")->second, 1, 6, system_status->OperatingSystem()->Name().c_str());
    terminal_ui->DrawWindows(windows);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    system_status = system_monitor->Status(system_status);
  }
  return 0;
}