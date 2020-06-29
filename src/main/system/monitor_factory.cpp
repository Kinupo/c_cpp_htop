#include "system/monitor_factory.h"

std::shared_ptr<ProcessesMonitor> MonitorFactory::BuildProcessesMonitor(){
    return std::make_shared<ProcessesMonitor>();
}

std::shared_ptr<SystemMonitor> MonitorFactory::BuildSystemMonitor(){
    return std::make_shared<SystemMonitor>(
        MonitorFactory::BuildOperatingSystemMonitor(),
        MonitorFactory::BuildProcessesMonitor());
};

std::shared_ptr<OperatingSystemMonitor> MonitorFactory::BuildOperatingSystemMonitor(){
    return std::make_shared<OperatingSystemMonitor>();
};

