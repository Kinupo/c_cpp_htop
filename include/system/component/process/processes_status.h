#ifndef PROCESSES_STATUS_H
#define PROCESSES_STATUS_H

#include "system/component/process/process_status.h"
#include "system/component/component_status.h"

#include <vector>
#include <memory>
/*
* Contains processes information and an unsorted collection of running processes.
*/
class ProcessesStatus : public ComponentStatus{
  private:
   const int number_of_running_processes;
   const int number_of_processes;
   const std::shared_ptr<std::vector<ProcessStatus>> running_processes;
   const ComponentType componentType = kProcesses;
  public:
    ProcessesStatus(
      int number_of_running_processes, 
      int number_of_processes,
      const std::shared_ptr<std::vector<ProcessStatus>> running_processes);
    int NumberOfRunningProcesses();
    int NumberOfProcesses();
    const std::shared_ptr<std::vector<ProcessStatus>> RunningProcesses();
    ComponentType Component();
};

#endif