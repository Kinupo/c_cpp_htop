#ifndef PROCESSORS_MONITOR_H
#define PROCESSORS_MONITOR_H

#include "system/component/component_monitor.h"
#include "system/status_monitor.h"
#include "system/component/cpu/processors_status.h"

class ProcessorsMonitor : public ComponentMonitor {
    private:
        const ComponentType componentType = kCpu;
    public:
        std::shared_ptr<ComponentStatus> Status();
        std::shared_ptr<ComponentStatus> Status(std::shared_ptr<ComponentStatus> prior_status);
        ComponentType ComponentMonitored();
};

#endif