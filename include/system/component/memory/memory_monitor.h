#ifndef MEMORY_MONITOR_H
#define MEMORY_MONITOR_H

#include "system/component/component_monitor.h"
#include "system/component/memory/memory_status.h"
#include "system/status_monitor.h"

#include <memory>

class MemoryMonitor : public ComponentMonitor {
    private:
        const ComponentType componentType = kMemory;
    public:
        std::shared_ptr<ComponentStatus> Status();
        std::shared_ptr<ComponentStatus> Status(std::shared_ptr<ComponentStatus> prior_status);
        ComponentType ComponentMonitored();
};

#endif