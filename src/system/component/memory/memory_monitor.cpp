#include "system/component/memory/memory_monitor.h"

std::shared_ptr<ComponentStatus> MemoryMonitor::Status(){

    auto mem_info = FileReader::ReadLines(kMeminfo, keys_);

    auto parsed_total_memory = DelimitedParser::ParseTrimKey(
                                                    kKeyTotalMemory, 
                                                    (*mem_info)[kKeyTotalMemory], 
                                                    ' ');

    auto parsed_free_memory = DelimitedParser::ParseTrimKey(
                                                    kKeyFreeMemory, 
                                                    (*mem_info)[kKeyFreeMemory], 
                                                    ' ');

    int total_memory = std::stoi((*parsed_total_memory).at(0));
    int free_memory = std::stoi((*parsed_free_memory).at(0));

    return std::make_shared<MemoryStatus>(total_memory,  total_memory-free_memory);
};

std::shared_ptr<ComponentStatus> MemoryMonitor::Status(
    std::shared_ptr<ComponentStatus> prior_status){
    return Status();
};

ComponentType MemoryMonitor::ComponentMonitored(){return component_type_;};

