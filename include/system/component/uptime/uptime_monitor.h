#ifndef UPTIME_MONITOR_H
#define UPTIME_MONITOR_H

#include "system/status_monitor.h"
#include "system/component/uptime/uptime.h"
#include "system/component/component_monitor.h"

#include <memory>

class UptimeMonitor : public StatusMonitor<std::unique_ptr<Uptime>>, ComponentMonitor{
    private:
        const ComponentType componentType = kUptime;
    public:
        std::unique_ptr<Uptime> status();
        std::unique_ptr<Uptime> status(std::unique_ptr<Uptime>);
        ComponentType ComponentMonitored();
};

#endif