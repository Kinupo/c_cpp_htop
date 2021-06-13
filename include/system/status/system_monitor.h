#ifndef SYSTEM_MONITOR_H
#define SYSTEM_MONITOR_H

#include "system/status_monitor.h"
#include "system/component/component_monitor.h"
#include "system/status/system_status.h"
#include "system/component/component_type.h"
#include "system/component/uptime/uptime_monitor.h"
#include "system/component/operating_system/operating_system_monitor.h"
#include "system/component/cpu/processors_monitor.h"

#include <memory>
#include <map>
#include <vector>
#include <iostream>

class SystemMonitor{
  private:
    std::map<ComponentType, std::unique_ptr<ComponentMonitor>> monitors_;
  public:
    SystemMonitor(std::vector<std::unique_ptr<ComponentMonitor>> &component_monitors);

    std::shared_ptr<SystemStatus> Status();
    std::shared_ptr<SystemStatus> Status(std::weak_ptr<SystemStatus> prior_status);
};

#endif