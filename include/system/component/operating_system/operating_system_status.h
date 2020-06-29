#ifndef OPERATING_SYSTEM_STATUS_H
#define OPERATING_SYSTEM_STATUS_H

#include "system/component/component_status.h"

#include <string>

class OperatingSystemStatus : public ComponentStatus{
  private:
    const std::string name;
    const std::string kernal_version;
    const ComponentType componentType = kOperatingSystem;
  public:
    OperatingSystemStatus(
        const std::string name, 
        const std::string kernal_version);
    const ComponentType Component();
    
    const std::string Name();
    const std::string KernalVersion();
};


#endif