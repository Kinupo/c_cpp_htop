#ifndef COMPONENT_MONITOR_H
#define COMPONENT_MONITOR_H

#include "system/component/component_type.h"

class ComponentMonitor {
    public:
        virtual ComponentType ComponentMonitored() = 0;
};

#endif