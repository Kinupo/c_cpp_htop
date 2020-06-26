#include "system/status/system_monitor.h"

SystemMonitor::SystemMonitor(std::shared_ptr<OperatingSystemMonitor> operating_system_monitor_) :
    operating_system_monitor(operating_system_monitor_){

};

std::shared_ptr<SystemStatus> SystemMonitor::Status(){
    return std::make_shared<SystemStatus>(operating_system_monitor->Status());
};

std::shared_ptr<SystemStatus> SystemMonitor::Status(std::shared_ptr<SystemStatus> prior_status){
    return std::make_shared<SystemStatus>(
        operating_system_monitor->Status(prior_status->OperatingSystem())
    );
};