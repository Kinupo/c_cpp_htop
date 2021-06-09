#ifndef PROCESSORS_STATUS_H
#define PROCESSORS_STATUS_H

#include "system/component/component_status.h"

#include <memory>

class ProcessorsStatus : public ComponentStatus{
 private:
    const float idle_time_;
    const float active_time_;
    const float prior_idle_time_;
    const float prior_active_time_;
    const ComponentType component_type_ = kCpu;
 public:
  ProcessorsStatus(const float idle_time, const float active_time);
  ProcessorsStatus(const float idle_time, const float active_time, std::shared_ptr<ComponentStatus> prior_status);
  ComponentType Component();

  //Utilization of all cores as a percentage of active time/total time
  float Utilization();
};

#endif