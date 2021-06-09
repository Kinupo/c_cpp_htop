#include "system/monitor_factory.h"

std::unique_ptr<SystemMonitor> MonitorFactory::BuildSystemMonitor(){
    std::vector<std::unique_ptr<ComponentMonitor>> monitors;
    monitors.push_back(MonitorFactory::BuildUptimeMonitor());
    monitors.push_back(MonitorFactory::BuildOperatingSystemMonitor());
    monitors.push_back(MonitorFactory::BuildProcessesMonitor());
    monitors.push_back(MonitorFactory::BuildProcessorsMonitor());
    monitors.push_back(MonitorFactory::BuildMemoryMonitor());
    return std::make_unique<SystemMonitor>(monitors);
}

std::unique_ptr<ProcessesMonitor> MonitorFactory::BuildProcessesMonitor(){
    return std::make_unique<ProcessesMonitor>();
}

std::unique_ptr<ProcessorsMonitor> MonitorFactory::BuildProcessorsMonitor(){
    return std::make_unique<ProcessorsMonitor>();
}

std::unique_ptr<MemoryMonitor> MonitorFactory::BuildMemoryMonitor(){
    return std::make_unique<MemoryMonitor>();
}

std::unique_ptr<OperatingSystemMonitor> MonitorFactory::BuildOperatingSystemMonitor(){
    return std::make_unique<OperatingSystemMonitor>();
}

std::unique_ptr<UptimeMonitor> MonitorFactory::BuildUptimeMonitor(){
    return std::make_unique<UptimeMonitor>();
}
