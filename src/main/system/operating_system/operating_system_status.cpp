#include "system/operating_system/operating_system_status.h"

OperatingSystemStatus::OperatingSystemStatus(
        const std::string name_, 
        const std::string kernal_version_) 
    : name(name_), kernal_version(kernal_version_)
        {}

const std::string OperatingSystemStatus::Name(){return name;}
const std::string OperatingSystemStatus::KernalVersion(){return kernal_version;}