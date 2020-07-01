#ifndef PROCESS_MONITOR_H
#define PROCESS_MONITOR_H

#include "system/status_monitor.h"
#include "system/component/process/processes_status.h"
#include "system/component/component_monitor.h"

#include <memory>

class ProcessesMonitor : public ComponentMonitor{
    private:
        const ComponentType componentType = kProcesses;
    public:
        std::shared_ptr<ComponentStatus> Status();
        std::shared_ptr<ComponentStatus> Status(std::shared_ptr<ComponentStatus> prior_status);
        ComponentType ComponentMonitored();
};

#endif