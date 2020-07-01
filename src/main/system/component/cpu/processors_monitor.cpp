#include "system/component/cpu/processors_monitor.h"

std::shared_ptr<ComponentStatus> ProcessorsMonitor::Status(){
    return Status(nullptr);
}

std::shared_ptr<ComponentStatus> ProcessorsMonitor::Status(std::shared_ptr<ComponentStatus> prior_status){
    return std::make_shared<ProcessorsStatus>(100.0, 1000.0, prior_status);
}

ComponentType ProcessorsMonitor::ComponentMonitored(){return componentType;}