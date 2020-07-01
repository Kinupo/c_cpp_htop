#include "system/component/memory/memory_monitor.h"

std::shared_ptr<ComponentStatus> MemoryMonitor::Status(){
    return std::make_shared<MemoryStatus>(1000, 2000);
};

std::shared_ptr<ComponentStatus> MemoryMonitor::Status(std::shared_ptr<ComponentStatus> prior_status){
    return Status();
};

ComponentType MemoryMonitor::ComponentMonitored(){return componentType;};

