#ifndef MEMORY_MONITOR_H
#define MEMORY_MONITOR_H

#include <memory>
#include <vector>

#include "system/component/component_monitor.h"
#include "system/component/memory/memory_status.h"
#include "system/status_monitor.h"
#include "file_reader/file_reader.h"
#include "parser/delimited_parser.h"

class MemoryMonitor : public ComponentMonitor {
    private:
        const ComponentType component_type_ = kMemory;
        const std::string kMeminfo = "/proc/meminfo";
        const std::string kKeyTotalMemory = "MemTotal:";
        const std::string kKeyFreeMemory = "MemFree:";
        const std::vector<std::string> keys_ = {kKeyTotalMemory, kKeyFreeMemory};
        std::string Trim(const std::string string_to_trim);
        int ParseMemoryInfo(const std::string key, const std::string unparsed_memory_info);
    public:
        std::shared_ptr<ComponentStatus> Status();
        std::shared_ptr<ComponentStatus> Status(std::shared_ptr<ComponentStatus> prior_status);
        ComponentType ComponentMonitored();
};

#endif