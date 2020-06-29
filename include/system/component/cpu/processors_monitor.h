#ifndef PROCESSORS_MONITOR_H
#define PROCESSORS_MONITOR_H

#include "system/component/component_monitor.h"
#include "system/status_monitor.h"
#include "system/component/cpu/processors_status.h"

class ProcessorMonitor : public StatusMonitor<std::shared_ptr<ProcessorsStatus>>, ComponentMonitor {
    private:
        const ComponentType componentType = kCpu;
    public:
        std::shared_ptr<ProcessorsStatus> Status();
        std::shared_ptr<ProcessorsStatus> Status(std::shared_ptr<ProcessorsStatus> prior_status);
        ComponentType ComponentMonitored();
};

#endif