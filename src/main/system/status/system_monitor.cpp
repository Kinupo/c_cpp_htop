#include "system/status/system_monitor.h"
#include "system/component/uptime/uptime_monitor.h"
#include "system/component/operating_system/operating_system_monitor.h"

#include <vector>
#include <iostream>

SystemMonitor::SystemMonitor(const std::vector<std::shared_ptr<ComponentMonitor>> component_monitors_){
    for(auto component_monitor : component_monitors_)
        monitors.insert(std::make_pair(component_monitor->ComponentMonitored(),  component_monitor));
}

std::string print_status(std::shared_ptr<ComponentStatus> comp_mon){
    return comp_mon == nullptr ? " status is null "
    : std::dynamic_pointer_cast<OperatingSystemStatus>(comp_mon) == nullptr ?"null post cast" 
        : std::dynamic_pointer_cast<OperatingSystemStatus>(comp_mon) ->Name();
}

std::shared_ptr<SystemStatus> SystemMonitor::Status(){
    return Status(nullptr);
}

std::shared_ptr<SystemStatus> SystemMonitor::Status(std::shared_ptr<SystemStatus> prior_status){
    std::vector<std::shared_ptr<ComponentStatus>> component_statuses;
    for(auto monitor:monitors){
        // std::cout << "monitor loop" << "\n";
        // std::cout << monitor.second->ComponentMonitored() << " status " << monitor.second->Status() << " " << 
        //     ((kOperatingSystem == monitor.first) ? print_status(monitor.second->Status()) : " Not OS")
        //     <<"\n";
        // std::cout << (monitor.second == nullptr ? "monitor " 
        //     : (monitor.second->Status() == nullptr ? " monitor status": " not null"));
        component_statuses.push_back(monitor.second->Status(
            nullptr == prior_status 
                ? nullptr 
                : prior_status->Component(monitor.first)));
    }
    return std::make_shared<SystemStatus>(component_statuses);
}