#ifndef STATUS_MONITOR_H
#define STATUS_MONITOR_H

#include "system/component/component_status.h"

#include <memory>

class StatusMonitor{
    public:
        virtual std::shared_ptr<ComponentStatus> Status() = 0;
        virtual std::shared_ptr<ComponentStatus> Status(std::shared_ptr<ComponentStatus> prior_status) = 0;
};

#endif