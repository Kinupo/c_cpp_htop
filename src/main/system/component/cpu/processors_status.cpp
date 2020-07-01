#include "system/component/cpu/processors_status.h"

double ProcessorsStatus::Utilization() { return active_time/(idle_time + active_time); }

std::shared_ptr<ProcessorsStatus> downcast(std::shared_ptr<ComponentStatus> prior_status){
  return std::dynamic_pointer_cast<ProcessorsStatus>(prior_status);
}

ProcessorsStatus::ProcessorsStatus(
    const double idle_time_, 
    const double active_time_): 
      ProcessorsStatus(idle_time_, active_time_, nullptr){}
      
ProcessorsStatus::ProcessorsStatus(
    const double idle_time_, 
    const double active_time_, 
    std::shared_ptr<ComponentStatus> prior_status)
      : idle_time(
        (nullptr == prior_status || downcast(prior_status) == nullptr)
          ? idle_time_ 
          : idle_time_ - downcast(prior_status)->idle_time), 
      active_time(
        (nullptr == prior_status || downcast(prior_status) == nullptr)
          ? active_time_ 
          : active_time_ - downcast(prior_status)->active_time) {}

ComponentType ProcessorsStatus::Component(){return componentType;}