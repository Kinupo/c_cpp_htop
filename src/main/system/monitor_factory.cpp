#include "system/monitor_factory.h"

template<typename T>
std::shared_ptr<ComponentMonitor> upcast(T monitor){
    std::shared_ptr<ComponentMonitor> upcasted = monitor;
    return upcasted;
}

std::shared_ptr<SystemMonitor> MonitorFactory::BuildSystemMonitor(){
    std::vector<std::shared_ptr<ComponentMonitor>> monitors = {
        upcast(MonitorFactory::BuildOperatingSystemMonitor()),
        upcast(MonitorFactory::BuildProcessesMonitor()),
        upcast(MonitorFactory::BuildProcessorsMonitor()),
        upcast(MonitorFactory::BuildMemoryMonitor()),
        upcast(MonitorFactory::BuildUptimeMonitor())
    };
    return std::make_shared<SystemMonitor>(monitors);
}

std::shared_ptr<ProcessesMonitor> MonitorFactory::BuildProcessesMonitor(){
    return std::make_shared<ProcessesMonitor>();
}

std::shared_ptr<ProcessorsMonitor> MonitorFactory::BuildProcessorsMonitor(){
    return std::make_shared<ProcessorsMonitor>();
}

std::shared_ptr<MemoryMonitor> MonitorFactory::BuildMemoryMonitor(){
    return std::make_shared<MemoryMonitor>();
}

std::shared_ptr<OperatingSystemMonitor> MonitorFactory::BuildOperatingSystemMonitor(){
    return std::make_shared<OperatingSystemMonitor>();
}

std::shared_ptr<UptimeMonitor> MonitorFactory::BuildUptimeMonitor(){
    return std::make_shared<UptimeMonitor>();
}
