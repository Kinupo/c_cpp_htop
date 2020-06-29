#ifndef PROCESS_MONITOR_H
#define PROCESS_MONITOR_H

#include "system/status_monitor.h"
#include "system/process/processes_status.h"
#include "system/component/component_monitor.h"

#include <memory>

class ProcessesMonitor : public StatusMonitor<std::unique_ptr<ProcessesStatus>>, ComponentMonitor{
    private:
        const ComponentType componentType = kProcesses;
    public:
        std::unique_ptr<ProcessesStatus> status();
        std::unique_ptr<ProcessesStatus> status(std::unique_ptr<ProcessesStatus>);
        ComponentType ComponentMonitored();
};

#endif