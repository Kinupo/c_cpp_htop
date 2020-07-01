#ifndef PROCESSORS_STATUS_H
#define PROCESSORS_STATUS_H

#include "system/component/component_status.h"

#include <memory>

class ProcessorsStatus : public ComponentStatus{
 private:
    const double idle_time;
    const double active_time;
    const ComponentType componentType = kCpu;
 public:
  ProcessorsStatus(const double idle_time, const double active_time);
  ProcessorsStatus(const double idle_time, const double active_time, std::shared_ptr<ComponentStatus> prior_status);
  ComponentType Component();

  //Utilization of all cores as a percentage of active time/total time
  double Utilization();
};

#endif