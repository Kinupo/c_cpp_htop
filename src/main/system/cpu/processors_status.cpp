#include "system/cpu/processors_status.h"

// TODO: Return the aggregate CPU utilization
const float ProcessorsStatus::Utilization() { return active_time/(idle_time + active_time); }

  ProcessorsStatus::ProcessorsStatus(
      const float idle_time_, 
      const float active_time_): 
        ProcessorsStatus(idle_time_, active_time_, nullptr){}
  ProcessorsStatus::ProcessorsStatus(
      const float idle_time_, 
      const float active_time_, 
      std::shared_ptr<ProcessorsStatus> prior_status)
        : idle_time(nullptr == prior_status ? idle_time_ : idle_time_ - prior_status->idle_time), 
        active_time(nullptr == prior_status ? active_time_ : active_time_ - prior_status->active_time) {}