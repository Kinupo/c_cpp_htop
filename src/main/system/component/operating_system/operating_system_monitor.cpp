#include "system/component/operating_system/operating_system_monitor.h"

#include<memory>

OperatingSystemMonitor::OperatingSystemMonitor(){}

std::shared_ptr<ComponentStatus> OperatingSystemMonitor::Status(){
    return std::make_shared<OperatingSystemStatus>("name", "version");
}

std::shared_ptr<ComponentStatus> OperatingSystemMonitor::Status(std::shared_ptr<ComponentStatus> prior_status){
    return std::make_shared<OperatingSystemStatus>("name2", "version2");
}

ComponentType OperatingSystemMonitor::ComponentMonitored(){return componentType;} 