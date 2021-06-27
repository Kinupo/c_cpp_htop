#include "system/status/system_monitor.h"

SystemMonitor::SystemMonitor(std::vector<std::unique_ptr<ComponentMonitor>> &component_monitors){
    for(auto&& component_monitor : component_monitors)
        monitors_[component_monitor->ComponentMonitored()] = move(component_monitor);
}

std::shared_ptr<SystemStatus> SystemMonitor::Status(){
    std::vector<std::shared_ptr<ComponentStatus>> component_statuses;
    for(auto &monitor:monitors_)
        component_statuses.push_back(monitor.second->Status());
    return std::make_shared<SystemStatus>(component_statuses);
}

std::shared_ptr<SystemStatus> SystemMonitor::Status(std::weak_ptr<SystemStatus> prior_status){
    std::vector<std::shared_ptr<ComponentStatus>> component_statuses;
    for(auto &monitor:monitors_){
        component_statuses.push_back(
            monitor.second->Status(prior_status.lock()->Component(monitor.first)));
    }
    return std::make_shared<SystemStatus>(component_statuses);
}