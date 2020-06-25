#include "system/system_monitor_factory.h";
#include "system/component_monitor.h";

#include <vector>

ProcessMonitor *SystemMonitorFactory::processMonitor(){
    return nullptr;
}

SystemMonitor *SystemMonitorFactory::systemMonitor(){
    std::vector<ComponentMonitor*> componentMonitors{
        processMonitor()
    };

    return new SystemMonitor(componentMonitors);
}

