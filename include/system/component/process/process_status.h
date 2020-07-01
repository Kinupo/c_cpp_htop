#ifndef PROCESS_STATUS_H
#define PROCESS_STATUS_H

#include "system/user/user.h"

#include <string>
#include <memory>

class ProcessStatus {
 private:
  const int pid;
  const std::string command;
  
  const std::shared_ptr<User> owner;
  
  const float cpu_utilization;
  const float memory;
  const long uptime;
  
 public:
  ProcessStatus(
    int pid, 
    const std::string command,
    const std::shared_ptr<User> owner,
    float cpu_utilization,
    float memory,
    long uptime);

  int Pid();
  const std::string Command();
  
  const std::shared_ptr<User> Owner();
  
  float CpuUtilization();
  //in MB
  float Memory();
  long  Uptime();

  //sort by cpu utilization
  bool operator<(ProcessStatus const& other_process) const;  

};

#endif