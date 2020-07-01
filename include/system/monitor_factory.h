#ifndef MONITOR_FACTORY_H
#define MONITOR_FACTORY_H

#include "system/component/operating_system/operating_system_monitor.h"
#include "system/component/cpu/processors_monitor.h"
#include "system/component/memory/memory_monitor.h"
#include "system/component/process/processes_monitor.h"
#include "system/component/uptime/uptime_monitor.h"
#include "system/status/system_monitor.h"

#include <memory>

class MonitorFactory{
  public:
    std::shared_ptr<SystemMonitor> BuildSystemMonitor();
    std::shared_ptr<ProcessesMonitor> BuildProcessesMonitor();
    std::shared_ptr<OperatingSystemMonitor> BuildOperatingSystemMonitor();
    std::shared_ptr<ProcessorsMonitor> BuildProcessorsMonitor();
    std::shared_ptr<MemoryMonitor> BuildMemoryMonitor();
    std::shared_ptr<UptimeMonitor> BuildUptimeMonitor();
};

#endif