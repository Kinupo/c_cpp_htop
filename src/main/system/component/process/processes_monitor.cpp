#include "system/component/process/processes_monitor.h"

std::shared_ptr<ComponentStatus> ProcessesMonitor::Status(){
    return std::make_shared<ProcessesStatus>(12, 200, nullptr);
}

std::shared_ptr<ComponentStatus> ProcessesMonitor::Status(std::shared_ptr<ComponentStatus>){
    return Status();
}

ComponentType ProcessesMonitor::ComponentMonitored(){return componentType;}