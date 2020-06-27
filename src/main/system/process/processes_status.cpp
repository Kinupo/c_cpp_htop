#include "system/process/processes_status.h"

const int ProcessesStatus::NumberOfRunningProcesses(){
    return number_of_running_processes;
};
const int ProcessesStatus::NumberOfProcesses(){
    return number_of_processes;
};
const std::vector<ProcessStatus> ProcessesStatus::RunningProcesses(){
    return running_processes;
};