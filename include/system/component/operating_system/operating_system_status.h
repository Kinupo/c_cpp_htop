#ifndef OPERATING_SYSTEM_STATUS_H
#define OPERATING_SYSTEM_STATUS_H

#include "system/component/component_status.h"

#include <string>

class OperatingSystemStatus : public ComponentStatus{
  private:
    const std::string name_;
    const std::string kernal_version_;
    const ComponentType component_type_ = kOperatingSystem;
  public:
    OperatingSystemStatus(
        const std::string name, 
        const std::string kernal_version);
    ComponentType Component();
    
    const std::string Name();
    const std::string KernalVersion();
};


#endif