#ifndef OPERATING_SYSTEM_MONITOR_H
#define OPERATING_SYSTEM_MONITOR_H

#include <memory>
#include <vector>

#include "system/component/component_monitor.h"
#include "system/component/operating_system/operating_system_status.h"
#include "system/status_monitor.h"
#include "file_reader/file_reader.h"
#include "parser/delimited_parser.h"

/**
 * Monitors the operating system name and version
 **/
class OperatingSystemMonitor : public ComponentMonitor{
    private:
        const ComponentType component_type_ = kOperatingSystem;
        const std::string kVersionFilename{"/proc/version"};
        const std::string kOsPath{"/etc/os-release"};
        std::string FindVersion();
        std::string FindOsName();
        std::vector<std::string> os_keys = {"PRETTY_NAME"};
    public:
        OperatingSystemMonitor();
        std::shared_ptr<ComponentStatus> Status();
        std::shared_ptr<ComponentStatus> Status(std::shared_ptr<ComponentStatus> prior_status);
        ComponentType ComponentMonitored();
};

#endif