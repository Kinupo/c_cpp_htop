#ifndef PROCESSES_STATUS_H
#define PROCESSES_STATUS_H

#include "system/process/process_status.h"
#include "system/component/component_status.h"

#include <vector>
/*
* Contains processes information and an unsorted collection of running processes.
*/
class ProcessesStatus : public ComponentStatus{
  private:
   const int number_of_running_processes;
   const int number_of_processes;
   const std::vector<ProcessStatus> running_processes;
   const ComponentType componentType = kProcesses;
  public:
    ProcessesStatus(
      const int number_of_running_processes, 
      const int number_of_processes,
      const std::vector<ProcessStatus> running_processes);
    const int NumberOfRunningProcesses();
    const int NumberOfProcesses();
    const std::vector<ProcessStatus> RunningProcesses();
    const ComponentType Component();
};

#endif