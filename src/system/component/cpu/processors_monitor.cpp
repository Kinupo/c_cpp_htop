#include "system/component/cpu/processors_monitor.h"

std::shared_ptr<ComponentStatus> ProcessorsMonitor::Status(){
    return Status(nullptr);
}

float ProcessorsMonitor::SumOfActivity(
    std::vector<int> column_ids, std::vector<std::string> &raw_activity){
    float sum = 0;
    for(auto column_id:column_ids)
        sum += std::stof(raw_activity.at(column_id));
    return sum;
}

std::shared_ptr<ComponentStatus> ProcessorsMonitor::Status(
    std::shared_ptr<ComponentStatus> prior_status){
    
    auto unparsed_cpu_status = FileReader::ReadLines(kCpuUsageFilePath, keys_);

    auto trimmed_cpu_status = DelimitedParser::ParseTrimKey(
                                                    kKeyCpu, 
                                                    (*unparsed_cpu_status)[kKeyCpu], 
                                                    ' ');

    float idle = SumOfActivity(idle_columns_, *trimmed_cpu_status.get());
    float active = SumOfActivity(active_columns_, *trimmed_cpu_status.get());
    return std::make_shared<ProcessorsStatus>(idle, active, prior_status);
}

ComponentType ProcessorsMonitor::ComponentMonitored(){return component_type_;}