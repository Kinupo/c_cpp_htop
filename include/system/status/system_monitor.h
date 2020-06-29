#ifndef SYSTEM_MONITOR_H
#define SYSTEM_MONITOR_H

#include "system/status_monitor.h"
#include "system/component/component_monitor.h"
#include "system/status/system_status.h"
#include "system/component/component_type.h"

#include <memory>
#include <map>
#include <cstdarg>

class SystemMonitor : public StatusMonitor<std::shared_ptr<SystemStatus>>{
  private:
    const std::map<ComponentType, std::shared_ptr<ComponentMonitor>> monitors;
  public:
    SystemMonitor(std::shared_ptr<ComponentMonitor> component_monitors, ...);

    std::shared_ptr<SystemStatus> Status();
    std::shared_ptr<SystemStatus> Status(std::shared_ptr<SystemStatus> prior_status);
};

#endif