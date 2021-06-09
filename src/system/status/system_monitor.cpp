#include "system/status/system_monitor.h"
#include "system/component/uptime/uptime_monitor.h"
#include "system/component/operating_system/operating_system_monitor.h"
#include "system/component/cpu/processors_monitor.h"

#include <vector>
#include <iostream>

SystemMonitor::SystemMonitor(std::vector<std::unique_ptr<ComponentMonitor>> &component_monitors){
    for(auto&& component_monitor : component_monitors)
        monitors_[component_monitor->ComponentMonitored()] = move(component_monitor);
}

std::shared_ptr<SystemStatus> SystemMonitor::Status(){
    return Status(nullptr);
}

std::shared_ptr<SystemStatus> SystemMonitor::Status(std::shared_ptr<SystemStatus> prior_status){
    std::vector<std::shared_ptr<ComponentStatus>> component_statuses;
    for(auto &monitor:monitors_){
        component_statuses.push_back(monitor.second->Status(
            nullptr == prior_status 
                ? nullptr 
                : prior_status->Component(monitor.first)));
    }
    return std::make_shared<SystemStatus>(component_statuses);
}