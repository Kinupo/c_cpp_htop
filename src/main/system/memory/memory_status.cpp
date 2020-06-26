#include "system/memory/memory_status.h"

MemoryStatus::MemoryStatus(const int total_, const int used_)
    : total(total_), used(used_) {};
//as percentage 
const float MemoryStatus::Utilization(){
    return used/total;
};