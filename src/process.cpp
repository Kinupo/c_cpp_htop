#include "process.h"

Process::Process(
    int pid, 
    std::string user, 
    std::string command, 
    float cpu_utilization, 
    std::string ram, 
    long int up_time)
:pid_(pid), 
 user_(user), 
 command_(command),
 cpu_utilization_(cpu_utilization),
 ram_(ram),
 up_time_(up_time)
{};

// TODO: Return this process's ID
int Process::Pid() { return pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() { return cpu_utilization_; }

// TODO: Return the command that generated this process
std::string Process::Command() { return command_; }

// TODO: Return this process's memory utilization
std::string Process::Ram() { return ram_; }

// TODO: Return the user (name) that generated this process
std::string Process::User() { return user_; }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return up_time_; }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& other_process) const { 
    return  other_process.cpu_utilization_ < cpu_utilization_;
}