#ifndef PROCESSORS_STATUS_H
#define PROCESSORS_STATUS_H

#include <memory>

class ProcessorsStatus {
 private:
    const float idle_time;
    const float active_time;
 public:
  ProcessorsStatus(const float idle_time, const float active_time);
  ProcessorsStatus(const float idle_time, const float active_time, std::shared_ptr<ProcessorsStatus> prior_status);
  //Utilization of all cores as a percentage of active time/total time
  const float Utilization();
};

#endif