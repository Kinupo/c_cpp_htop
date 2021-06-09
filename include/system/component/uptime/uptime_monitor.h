#ifndef UPTIME_MONITOR_H
#define UPTIME_MONITOR_H

#include "system/status_monitor.h"
#include "system/component/uptime/uptime.h"
#include "system/component/component_monitor.h"
#include "system/up_time/up_time_service.h"

#include <memory>

class UptimeMonitor : public ComponentMonitor{
    private:
        const ComponentType component_type_ = kUptime;
    public:
        std::shared_ptr<ComponentStatus> Status();
        std::shared_ptr<ComponentStatus> Status(std::shared_ptr<ComponentStatus> prior_status);
        ComponentType ComponentMonitored();
};

#endif