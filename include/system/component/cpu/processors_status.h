#ifndef PROCESSORS_STATUS_H
#define PROCESSORS_STATUS_H

#include "system/component/component_status.h"

#include <memory>

class ProcessorsStatus : public ComponentStatus{
 private:
    const float idle_time;
    const float active_time;
    const ComponentType componentType = kCpu;
 public:
  ProcessorsStatus(const float idle_time, const float active_time);
  ProcessorsStatus(const float idle_time, const float active_time, std::shared_ptr<ProcessorsStatus> prior_status);
  const ComponentType Component();

  //Utilization of all cores as a percentage of active time/total time
  const float Utilization();
};

#endif