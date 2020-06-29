#ifndef MONITOR_FACTORY_H
#define MONITOR_FACTORY_H

#include "system/operating_system/operating_system_monitor.h"
#include "system/process/processes_monitor.h"
#include "system/status/system_monitor.h"

#include <memory>

class MonitorFactory{
  public:
    std::shared_ptr<SystemMonitor> BuildSystemMonitor();
    std::shared_ptr<ProcessesMonitor> BuildProcessesMonitor();
    std::shared_ptr<OperatingSystemMonitor> BuildOperatingSystemMonitor();
};

#endif