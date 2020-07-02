#include "system/monitor_factory.h"
#include "terminal_ui/terminal_ui.h"

#include "terminal_ui/view/view.h"
#include "terminal_ui/view/border.h"
#include "terminal_ui/view/title.h"


#include <curses.h>
#include <thread>
#include <chrono>
#include <memory>

#include <map>

#include <iostream>

std::shared_ptr<std::map<std::string, WINDOW*>> CreateWindows(TerminalUi &terminal_ui){

  
  std::vector<Row> rows;
  Dimension system_dimension(7, -1);
  Title system_title("System", Position(6, 0));
  View system_view("System", std::make_shared<Border>(system_title), rows, system_dimension, Position(0, 0));
  auto system_window = terminal_ui.CreateWindow(*system_view.Dimensions());

  box(system_window, system_view.RelativePosition().Y(), system_view.RelativePosition().X());
  auto title = system_view.BorderElement()->TitleElement();
  mvwprintw(system_window, title.RelativePosition().Y(), title.RelativePosition().X(), title.Text().c_str());


  auto process_window = terminal_ui.CreateWindowBelow(
    system_window, 
    -1, 
    -1);

  auto windows = std::make_unique<std::map<std::string, WINDOW*>>();
  windows->insert(std::pair<std::string, WINDOW*>{"Process", process_window});
  windows->insert(std::pair<std::string, WINDOW*>{"System", system_window});
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

  // std::cout << "\n" << (system_status->Component(kOperatingSystem) == nullptr ? "no OS status" : "OS statis is present") << "\n";

  // auto puff = std::dynamic_pointer_cast<OperatingSystemStatus>(system_status->Component(kOperatingSystem));
  // std::cout << (system_status->Component(kOperatingSystem) == nullptr ? " os is null" :  " os is not null") << "\n";//puff->Name()) << "\n";
  
  auto terminal_ui = BuildTerminalUi();
  terminal_ui->InitilizeTerminal();

  auto windows = CreateWindows(*terminal_ui);

  box(windows->find("Process")->second, 0, 0);
  
  while(1){
    // auto xxxx = system_status->Component(kOperatingSystem);
    std::shared_ptr<OperatingSystemStatus> oss = std::dynamic_pointer_cast<OperatingSystemStatus>(system_status->Component(kOperatingSystem));

    mvwprintw(windows->find("System")->second, 1, 6, 
    // xxxx == nullptr ? "yes" : "no");
      oss->Name().c_str());
    terminal_ui->DrawWindows(*windows);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    system_status = system_monitor->Status(system_status);
  }
  return 0;
}