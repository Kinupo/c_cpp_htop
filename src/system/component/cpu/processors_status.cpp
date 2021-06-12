#include "system/component/cpu/processors_status.h"

float ProcessorsStatus::Utilization() {
  float total_time = (idle_time_ + active_time_);
  if(total_time < 1)
    total_time = 1;
  return active_time_/total_time;
}

std::shared_ptr<ProcessorsStatus> downcast(std::shared_ptr<ComponentStatus> prior_status){
  return std::dynamic_pointer_cast<ProcessorsStatus>(prior_status);
}

ProcessorsStatus::ProcessorsStatus(
    const float idle_time, 
    const float active_time): 
      ProcessorsStatus(idle_time, active_time, nullptr){}
      
ProcessorsStatus::ProcessorsStatus(
    const float idle_time, 
    const float active_time, 
    std::shared_ptr<ComponentStatus> prior_status)
      : idle_time_(
        (nullptr == prior_status || downcast(prior_status) == nullptr)
          ? idle_time 
          : idle_time - downcast(prior_status)->idle_time_), 
      active_time_(
        (nullptr == prior_status || downcast(prior_status) == nullptr)
          ? active_time 
          : active_time - downcast(prior_status)->active_time_) {}

ComponentType ProcessorsStatus::Component(){return component_type_;}