#include "system/component/memory/memory_status.h"

MemoryStatus::MemoryStatus(const int total, const int used)
    : total_(total), used_(used) {};
    
//as percentage 
float MemoryStatus::Utilization(){
    return (float)used_/(float)total_;
};

ComponentType MemoryStatus::Component(){return componentType_;};