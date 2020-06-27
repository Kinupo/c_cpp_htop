#ifndef PROCESS_STATUS_H
#define PROCESS_STATUS_H

#include "system/user/user.h"

#include <string>
#include <memory>

class ProcessStatus {
 public:
  const int Pid();
  std::shared_ptr<User>  User();
  const std::string Command();
  const float CpuUtilization();
  //in MB
  const float Memory();
  const long int Uptime();

  //sort by cpu utilization
  bool operator<(ProcessStatus const& other_process) const;  

};

#endif