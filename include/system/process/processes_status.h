#ifndef PROCESSES_STATUS_H
#define PROCESSES_STATUS_H

#include "system/process/process_status.h"

#include <vector>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class ProcessesStatus {
  private:
   const int number_of_running_processes;
   const int number_of_processes;
   const std::vector<ProcessStatus> running_processes;
  public:
    int NumberOfRunningProcesses();
    int NumberOfProcesses();
    std::vector<ProcessesStatus> RunningProcesses();
};

#endif