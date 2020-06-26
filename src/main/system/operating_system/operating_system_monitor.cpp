#include "system/operating_system/operating_system_monitor.h"

#include<memory>

std::shared_ptr<OperatingSystemStatus> OperatingSystemMonitor::Status(){
    return std::make_shared<OperatingSystemStatus>("name", "version");
}

std::shared_ptr<OperatingSystemStatus> OperatingSystemMonitor::Status(std::shared_ptr<OperatingSystemStatus> prior_status){
    return std::make_shared<OperatingSystemStatus>("name2", "version2");
}