#ifndef SYSTEM_MONITOR_H
#define SYSTEM_MONITOR_H

class SystemMonitor
{
  private:
    /* data */
  public:
    SystemMonitor(std::vector<ComponentMonitor*> component_monitors);
    ~SystemMonitor();
};

#endif