#ifndef SYSTEM_MONITOR_H
#define SYSTEM_MONITOR_H

#include "system/status_monitor.h"
#include "system/status/system_status.h"
#include "system/operating_system/operating_system_monitor.h"

#include <memory>

class SystemMonitor : public StatusMonitor<std::shared_ptr<SystemStatus>> {
  private:
    std::shared_ptr<OperatingSystemMonitor> operating_system_monitor;
  public:
    SystemMonitor(std::shared_ptr<OperatingSystemMonitor> operating_system_monitor);

    std::shared_ptr<SystemStatus> Status();
    std::shared_ptr<SystemStatus> Status(std::shared_ptr<SystemStatus> prior_status);
};

#endif