#include "system/status/system_status.h"

SystemStatus::SystemStatus(std::vector<std::shared_ptr<ComponentStatus>> component_statuses){
    for(auto status:component_statuses){
        statuses.insert(std::make_pair(status->Component(), status));
    }
}

const std::shared_ptr<ComponentStatus> SystemStatus::Component(const ComponentType component){
    auto component_status_pair = statuses.find(component);
    if(component_status_pair != statuses.end())
        return component_status_pair->second;
    else
        return nullptr;
}