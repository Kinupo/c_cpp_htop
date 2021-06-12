#include "system/component/process/process_status.h"

 ProcessStatus::ProcessStatus(
    int pid, 
    const std::string command,
    const int owner_id,
    float cpu_utilization,
    float memory,
    long up_time)
    : pid_(pid),
      command_(command),
      owner_id_(owner_id),
      cpu_utilization_(cpu_utilization),
      memory_(memory),
      up_time_(up_time)
    {}

int ProcessStatus::Pid() { return pid_; }

float ProcessStatus::CpuUtilization() { return cpu_utilization_; }

const std::string ProcessStatus::Command() { return command_; }

std::string ProcessStatus::Memory() { 
  auto memory = std::to_string(memory_);
  auto decimal_pos = memory.find(".");
  if(decimal_pos != std::string::npos)
    return memory.substr(0, decimal_pos + 2); 
  return "0.00";
}

int ProcessStatus::OwnerId() { return owner_id_; }

long int ProcessStatus::UpTime() { return up_time_; }

bool ProcessStatus::operator<(ProcessStatus const& other_process) const {
  return cpu_utilization_ < other_process.cpu_utilization_;
}

bool ProcessStatus::operator>(ProcessStatus const& other_process) const {
  return cpu_utilization_ > other_process.cpu_utilization_;
}

bool ProcessStatus::operator() (ProcessStatus const& this_process, ProcessStatus const& other_process) const{ 
  return (this_process < other_process);
}