#include "system/component/uptime/uptime_monitor.h"

std::shared_ptr<ComponentStatus> UptimeMonitor::Status(){
    return Status(nullptr);
}

std::shared_ptr<ComponentStatus> UptimeMonitor::Status(std::shared_ptr<ComponentStatus> prior_status){
    return std::make_shared<Uptime>(UpTimeService::CurrentUpTime());
}

ComponentType UptimeMonitor::ComponentMonitored(){return component_type_;}