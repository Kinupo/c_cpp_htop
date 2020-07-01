#ifndef OPERATING_SYSTEM_MONITOR_H
#define OPERATING_SYSTEM_MONITOR_H

#include "system/component/component_monitor.h"
#include "system/component/operating_system/operating_system_status.h"
#include "system/status_monitor.h"

#include <memory>

/**
 * Monitors the operating system name and version
 **/
class OperatingSystemMonitor : public ComponentMonitor{
    private:
        const ComponentType componentType = kOperatingSystem;
    public:
        OperatingSystemMonitor();
        std::shared_ptr<ComponentStatus> Status();
        std::shared_ptr<ComponentStatus> Status(std::shared_ptr<ComponentStatus> prior_status);
        ComponentType ComponentMonitored();
};

#endif