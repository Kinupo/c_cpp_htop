#ifndef MEMORY_STATUS_H
#define MEMORY_STATUS_H

#include "system/component/component_status.h"

class MemoryStatus : public ComponentStatus{
    private:
        const int total;
        const int used;
        const ComponentType componentType = kMemory;
    public:
        MemoryStatus(const int total, const int used);
        ComponentType Component();
        //as percentage 
        float Utilization();
};

#endif