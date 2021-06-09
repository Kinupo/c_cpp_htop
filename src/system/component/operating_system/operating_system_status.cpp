#include "system/component/operating_system/operating_system_status.h"

OperatingSystemStatus::OperatingSystemStatus(
        const std::string name, 
        const std::string kernal_version) 
    : name_(name), kernal_version_(kernal_version)
        {}

const std::string OperatingSystemStatus::Name(){return name_;}
const std::string OperatingSystemStatus::KernalVersion(){return kernal_version_;}
ComponentType OperatingSystemStatus::Component(){return component_type_;}