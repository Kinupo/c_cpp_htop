#ifndef PROCESS_MONITOR_H
#define PROCESS_MONITOR_H

#include <memory>
#include <unistd.h>
#include <filesystem>
#include <stdexcept>

#include "system/status_monitor.h"
#include "system/component/process/processes_status.h"
#include "system/component/component_monitor.h"
#include "file_reader/file_reader.h"
#include "parser/delimited_parser.h"
#include "system/up_time/up_time_service.h"

class ProcessesMonitor : public ComponentMonitor{
    private:
        
        const ComponentType component_type_ = kProcesses;

        const float kKbInMb = 1024;
        const long kTicksPerSecond = sysconf(_SC_CLK_TCK);

        const std::string kProcPath = "/proc";
        const std::string kProcessStatusPath = "/status";
        const std::string kProcessStatPath = "/stat";
        const std::string kProcessCommandPath = "/cmdline";
        const std::string kProcStatPath = "/proc/stat";
        
        const std::string kKeyTotalProcesses = "processes";
        const std::string kKeyRunningProcesses = "procs_running";
        const std::vector<std::string> keys_ = {kKeyTotalProcesses, kKeyRunningProcesses};
        
        const std::string kKeyUid = "Uid:";
        const std::string kKeyMemoryUsage = "VmSize:";
        const std::vector<std::string> process_keys_ = {kKeyUid, kKeyMemoryUsage};

        const int kColumnUserTime = 13;
        const int kColumnSystemTime = 14;
        const int kColumnStartTime = 21;

        int ParseUid(const std::string unparsed_status);
        float ParseMemoryUsage(const std::string unparsed_status);
        bool isNumber(std::string string);
        std::shared_ptr<std::vector<std::string>> FindActiveProcessDirectories();
        std::shared_ptr<ProcessStatus> FindProcessDetails(const std::string process, const int system_up_time);
        

    public:
        std::shared_ptr<ComponentStatus> Status();
        std::shared_ptr<ComponentStatus> Status(std::shared_ptr<ComponentStatus> prior_status);
        ComponentType ComponentMonitored();
};

#endif