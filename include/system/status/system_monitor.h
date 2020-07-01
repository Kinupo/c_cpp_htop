#ifndef SYSTEM_MONITOR_H
#define SYSTEM_MONITOR_H

#include "system/status_monitor.h"
#include "system/component/component_monitor.h"
#include "system/status/system_status.h"
#include "system/component/component_type.h"

#include <memory>
#include <map>
#include <vector>

class SystemMonitor{
  private:
    std::map<ComponentType, std::shared_ptr<ComponentMonitor>> monitors;
  public:
    SystemMonitor(const std::vector<std::shared_ptr<ComponentMonitor>> component_monitors);

    std::shared_ptr<SystemStatus> Status();
    std::shared_ptr<SystemStatus> Status(std::shared_ptr<SystemStatus> prior_status);
};

#endif