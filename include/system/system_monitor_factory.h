#ifndef SYSTEM_MONITOR_FACTORY_H
#define SYSTEM_MONITOR_FACTORY_H

#include "system/process/process_monitor.h"
#include "system/system_monitor.h"

class SystemMonitorFactory{
  private:
  public:
    SystemMonitor *systemMonitor();
    ProcessMonitor *processMonitor();

};

#endif