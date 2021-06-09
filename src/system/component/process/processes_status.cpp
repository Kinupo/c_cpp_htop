#include "system/component/process/processes_status.h"

ProcessesStatus::ProcessesStatus(
    int number_of_running_processes, 
    int number_of_processes,
    const std::vector<std::shared_ptr<ProcessStatus>> running_processes) :
        number_of_running_processes_(number_of_running_processes),
        number_of_processes_(number_of_processes),
        running_processes_(running_processes){}

int ProcessesStatus::NumberOfRunningProcesses(){
    return number_of_running_processes_;
}

int ProcessesStatus::NumberOfProcesses(){
    return number_of_processes_;
}

const std::vector<std::shared_ptr<ProcessStatus>> ProcessesStatus::RunningProcesses(){
    return running_processes_;
}

ComponentType ProcessesStatus::Component(){return component_type_;}