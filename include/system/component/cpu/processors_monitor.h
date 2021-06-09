#ifndef PROCESSORS_MONITOR_H
#define PROCESSORS_MONITOR_H

#include "system/component/component_monitor.h"
#include "system/status_monitor.h"
#include "system/component/cpu/processors_status.h"
#include "file_reader/file_reader.h"
#include "parser/delimited_parser.h"

class ProcessorsMonitor : public ComponentMonitor {
    private:
        const ComponentType component_type_ = kCpu;
        const std::string kCpuUsageFilePath{"/proc/stat"};
        const std::string kKeyCpu = "cpu ";
        const std::vector<std::string> keys_ = {kKeyCpu};
        const int kUser = 0;
        const int kNice= 1;
        const int kSystem = 2;
        const int kIdle = 3;
        const int kIoWait = 4;
        const int kIrq = 5;
        const int kSoftIrq = 6;
        const int kSteal = 7;
        const std::vector<int> idle_columns_ = {kIdle, kIoWait};
        const std::vector<int> active_columns_ = {kUser, kNice, kSystem, kIrq, kSoftIrq, kSteal};
        float SumOfActivity(std::vector<int> column_ids, std::vector<std::string> &raw_activity);
    public:
        std::shared_ptr<ComponentStatus> Status();
        std::shared_ptr<ComponentStatus> Status(std::shared_ptr<ComponentStatus> prior_status);
        ComponentType ComponentMonitored();
};

#endif