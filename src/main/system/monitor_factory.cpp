#include "system/monitor_factory.h"
// #include "system/process/process_monitor.h"

// ProcessMonitor *MonitorFactory::processMonitor(){
//     return new ProcessMonitor();
// }

std::shared_ptr<SystemMonitor> MonitorFactory::BuildSystemMonitor(){
    return std::make_shared<SystemMonitor>(MonitorFactory::BuildOperatingSystemMonitor());
};

std::shared_ptr<OperatingSystemMonitor> MonitorFactory::BuildOperatingSystemMonitor(){
    return std::make_shared<OperatingSystemMonitor>();
};

