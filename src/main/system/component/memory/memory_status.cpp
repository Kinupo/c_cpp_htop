#include "system/component/memory/memory_status.h"

MemoryStatus::MemoryStatus(const int total_, const int used_)
    : total(total_), used(used_) {};
    
//as percentage 
float MemoryStatus::Utilization(){
    return used/total;
};

ComponentType MemoryStatus::Component(){return componentType;};