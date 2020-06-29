#ifndef SYSTEM_STATUS_H
#define SYSTEM_STATUS_H

#include "system/component/component_status.h"
#include "system/component/component_type.h"

#include <cstdarg>
#include <memory>
#include <map>

class SystemStatus{
    private:
        const std::map<ComponentType,std::shared_ptr<ComponentStatus>> statuses;
    public:
        SystemStatus(const std::shared_ptr<ComponentStatus> component_status, ...);
        const std::shared_ptr<ComponentStatus> ComponentStatus(const ComponentType component);
};

#endif