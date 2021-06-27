#include "system.h"

System::System() { CacheStatus(); }

void System::CacheStatus() {
  if (current_status_ == nullptr)
    current_status_ = system_monitor_->Status();
  else
    current_status_ = system_monitor_->Status(current_status_);
}

// TODO: Return the system's CPU
Processor& System::Cpu() {
  auto component_status = current_status_->Component(ComponentType::kCpu);
  auto processor_status =
      dynamic_cast<ProcessorsStatus*>(component_status.get());
  cpu_.Utilization(processor_status->Utilization());
  return cpu_;
}

// TODO: Return a container composed of the system's processes
std::vector<Process>& System::Processes() {
  auto component_status = current_status_->Component(ComponentType::kProcesses);
  auto processor_status =
      dynamic_cast<ProcessesStatus*>(component_status.get());

  auto running_processes = processor_status->RunningProcesses();

  processes_.clear();
  for (auto process : running_processes) {
    Process display_process(process->Pid(),
                            user_repo_.FindUser(process->OwnerId())->Name(),
                            process->Command(), process->CpuUtilization(),
                            process->Memory(), process->UpTime());
    processes_.push_back(display_process);
  }

  std::sort(processes_.begin(), processes_.end());
  return processes_;
}

// TODO: Return the system's kernel identifier (string)
std::string System::Kernel() {
  auto component_status =
      current_status_->Component(ComponentType::kOperatingSystem);
  auto operating_system_status =
      dynamic_cast<OperatingSystemStatus*>(component_status.get());
  return operating_system_status->KernalVersion();
}

// TODO: Return the system's memory utilization
float System::MemoryUtilization() {
  auto component_status = current_status_->Component(ComponentType::kMemory);
  auto memory_status = dynamic_cast<MemoryStatus*>(component_status.get());
  return memory_status->Utilization();
}

// TODO: Return the operating system name
std::string System::OperatingSystem() {
  auto component_status =
      current_status_->Component(ComponentType::kOperatingSystem);
  auto operating_system_status =
      dynamic_cast<OperatingSystemStatus*>(component_status.get());
  return operating_system_status->Name();
}

// TODO: Return the number of processes actively running on the system
int System::RunningProcesses() {
  auto component_status = current_status_->Component(ComponentType::kProcesses);
  auto processes_status =
      dynamic_cast<ProcessesStatus*>(component_status.get());
  return processes_status->NumberOfProcesses();
}

// TODO: Return the total number of processes on the system
int System::TotalProcesses() {
  auto component_status = current_status_->Component(ComponentType::kProcesses);
  auto processes_status =
      dynamic_cast<ProcessesStatus*>(component_status.get());
  return processes_status->NumberOfRunningProcesses();
}

// TODO: Return the number of seconds since the system started running
long int System::UpTime() {
  auto component_status = current_status_->Component(ComponentType::kUptime);
  auto uptime = dynamic_cast<Uptime*>(component_status.get());
  return static_cast<long int>(uptime->Seconds());
}