#ifndef PROCESS_STATUS_H
#define PROCESS_STATUS_H

#include <string>

#include "system/user/user.h"

class ProcessStatus {
 private:
  const int pid_;
  const std::string command_;
  
  const int owner_id_;
  
  const float cpu_utilization_;
  const float memory_;
  const long up_time_;
  
 public:
  ProcessStatus(
    int pid, 
    const std::string command,
    const int owner_id,
    float cpu_utilization,
    float memory,
    long up_time);

  int Pid();
  const std::string Command();
  
  int OwnerId();

  float CpuUtilization();
  //in MB
  std::string Memory();
  long int UpTime();

  //sort by cpu utilization
  bool operator<(ProcessStatus const& other_process) const;
  bool operator>(ProcessStatus const& other_process) const;
  bool operator() (ProcessStatus const& this_process, ProcessStatus const& other_process) const;
};

#endif