#ifndef PROCESS_MONITOR_H
#define PROCESS_MONITOR_H

#include "system/status_monitor.h"
#include "system/process/processes_status.h"

#include <memory>

class ProcessMonitor : public StatusMonitor<std::unique_ptr<ProcessesStatus>>{
    private:
        /* data */
    public:
        std::unique_ptr<ProcessesStatus> status();
        std::unique_ptr<ProcessesStatus> status(std::unique_ptr<ProcessesStatus>);
};

#endif