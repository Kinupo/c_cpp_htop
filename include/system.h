#ifndef SYSTEM_H
#define SYSTEM_H

#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

#include "process.h"
#include "processor.h"
#include "system/monitor_factory.h"
#include "system/status/system_status.h"
#include "system/user/user_repository.h"

class System {

  // TODO: Define any necessary private members
  private:
    Processor cpu_ = Processor();
    std::vector<Process> processes_ = {};
    std::unique_ptr<SystemMonitor> system_monitor_ = MonitorFactory::BuildSystemMonitor();
    UserRepository user_repo_ = UserRepository();
    std::shared_ptr<SystemStatus> current_status_;

  public:
    System();

    void CacheStatus();

    Processor& Cpu();                   // TODO: See src/system.cpp
    std::vector<Process>& Processes();  // TODO: See src/system.cpp
    float MemoryUtilization();          // TODO: See src/system.cpp
    long UpTime();                      // TODO: See src/system.cpp
    int TotalProcesses();               // TODO: See src/system.cpp
    int RunningProcesses();             // TODO: See src/system.cpp
    std::string Kernel();               // TODO: See src/system.cpp
    std::string OperatingSystem();      // TODO: See src/system.cpp

};

#endif