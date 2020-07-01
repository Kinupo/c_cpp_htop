#include "system/component/uptime/uptime_monitor.h"

std::shared_ptr<ComponentStatus> UptimeMonitor::Status(){
    return std::make_shared<Uptime>(100);
}

std::shared_ptr<ComponentStatus> UptimeMonitor::Status(std::shared_ptr<ComponentStatus> prior_status){
    return std::make_shared<Uptime>(200);
}

ComponentType UptimeMonitor::ComponentMonitored(){return componentType;}