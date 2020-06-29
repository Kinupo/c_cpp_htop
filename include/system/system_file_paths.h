#ifndef SYSTEM_FILE_PATHS_H
#define SYSTEM_FILE_PATHS_H

#include <string>

namespace system_status_paths {
    const std::string kProcDirectory{"/proc/"};
    const std::string kCmdline{"/proc/{pid}/cmdline"};
    const std::string kCpuinfoFilename{"/cpuinfo"};
    const std::string kProcessStatus{"/proc/{pid}/status"};
    const std::string kProcessStat{"/proc/{pid}/stat"};
    const std::string kStatFilename{"/proc/stat"};
    const std::string kUptimeFilename{"/proc/uptime"};
    const std::string kMeminfoFilename{"/proc/meminfo"};
    const std::string kVersionFilename{"/proc/version"};
    const std::string kOSPath{"/etc/os-release"};
    const std::string kPasswordPath{"/etc/passwd"};
}

#endif