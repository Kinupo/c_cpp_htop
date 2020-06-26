#ifndef MONITOR_FACTORY_H
#define MONITOR_FACTORY_H

// #include "system/process/process_monitor.h"
#include "system/status/system_monitor.h"

#include <memory>

class MonitorFactory{
  public:
    std::shared_ptr<SystemMonitor> BuildSystemMonitor();
    // ProcessMonitor *processMonitor();
    std::shared_ptr<OperatingSystemMonitor> BuildOperatingSystemMonitor();
};

#endif