#ifndef SYSTEM_STATUS_H
#define SYSTEM_STATUS_H

#include "system/component/component_status.h"
#include "system/component/component_type.h"

#include <memory>
#include <map>
#include <vector>

class SystemStatus{
    private:
        std::map<ComponentType,std::shared_ptr<ComponentStatus>> statuses_;
    public:
        SystemStatus(std::vector<std::shared_ptr<ComponentStatus>> component_statuses);
        const std::shared_ptr<ComponentStatus> Component(const ComponentType component);
};

#endif