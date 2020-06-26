#ifndef MEMORY_MONITOR_H
#define MEMORY_MONITOR_H

#include "system/memory/memory_status.h"
#include "system/status_monitor.h"

#include <memory>

class MemoryMonitor : public StatusMonitor<std::shared_ptr<MemoryStatus>> {
    public:
        std::shared_ptr<MemoryStatus> Status();
        std::shared_ptr<MemoryStatus> Status(std::shared_ptr<MemoryStatus> prior_status);
};

#endif