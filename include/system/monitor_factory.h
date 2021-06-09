#ifndef MONITOR_FACTORY_H
#define MONITOR_FACTORY_H

#include "system/component/operating_system/operating_system_monitor.h"
#include "system/component/cpu/processors_monitor.h"
#include "system/component/memory/memory_monitor.h"
#include "system/component/process/processes_monitor.h"
#include "system/component/uptime/uptime_monitor.h"
#include "system/status/system_monitor.h"

#include <memory>

namespace MonitorFactory{
    std::unique_ptr<SystemMonitor> BuildSystemMonitor();
    std::unique_ptr<ProcessesMonitor> BuildProcessesMonitor();
    std::unique_ptr<OperatingSystemMonitor> BuildOperatingSystemMonitor();
    std::unique_ptr<ProcessorsMonitor> BuildProcessorsMonitor();
    std::unique_ptr<MemoryMonitor> BuildMemoryMonitor();
    std::unique_ptr<UptimeMonitor> BuildUptimeMonitor();
};

#endif