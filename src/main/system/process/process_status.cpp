#include "system/process/process_status.h"

const int ProcessStatus::Pid() { return 0; }

const float ProcessStatus::CpuUtilization() { return 0; }

const std::string ProcessStatus::Command() { return std::string(); }

const float ProcessStatus::Memory() { return 0.0; }

std::shared_ptr<User> ProcessStatus::Owner() { return nullptr; }

const long int ProcessStatus::Uptime() { return 0; }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool ProcessStatus::operator<(ProcessStatus const& a [[maybe_unused]]) const {
  return true;
}