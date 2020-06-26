#ifndef OPERATING_SYSTEM_MONITOR_H
#define OPERATING_SYSTEM_MONITOR_H

#include "system/operating_system/operating_system_status.h"
#include "system/status_monitor.h"

#include <memory>

/**
 * Monitors the operating system name and version
 **/
class OperatingSystemMonitor : public StatusMonitor<std::shared_ptr<OperatingSystemStatus>> {
    public:
        std::shared_ptr<OperatingSystemStatus> Status();
        std::shared_ptr<OperatingSystemStatus> Status(std::shared_ptr<OperatingSystemStatus> prior_status);
};

#endif