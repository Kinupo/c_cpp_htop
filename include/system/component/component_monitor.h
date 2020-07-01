#ifndef COMPONENT_MONITOR_H
#define COMPONENT_MONITOR_H

#include "system/component/component_type.h"
#include "system/status_monitor.h"

class ComponentMonitor : public StatusMonitor {
    public:
        virtual ComponentType ComponentMonitored() = 0;
};

#endif