#ifndef PROCESSORS_MONITOR_H
#define PROCESSORS_MONITOR_H

#include "system/status_monitor.h"
#include "system/cpu/processors_status.h"

class ProcessorMonitor : public StatusMonitor<std::shared_ptr<ProcessorsStatus>> {
    public:
        std::shared_ptr<ProcessorsStatus> Status();
        std::shared_ptr<ProcessorsStatus> Status(std::shared_ptr<ProcessorsStatus> prior_status);
};

#endif