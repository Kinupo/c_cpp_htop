#include "system/component/process/processes_status.h"

ProcessesStatus::ProcessesStatus(
    int number_of_running_processes_, 
    int number_of_processes_,
    const std::shared_ptr<std::vector<ProcessStatus>> running_processes_) :
        number_of_running_processes(number_of_running_processes_),
        number_of_processes(number_of_processes_),
        running_processes(running_processes_){}

int ProcessesStatus::NumberOfRunningProcesses(){
    return number_of_running_processes;
}

int ProcessesStatus::NumberOfProcesses(){
    return number_of_processes;
}

const std::shared_ptr<std::vector<ProcessStatus>> ProcessesStatus::RunningProcesses(){
    return running_processes;
}

ComponentType ProcessesStatus::Component(){return componentType;}