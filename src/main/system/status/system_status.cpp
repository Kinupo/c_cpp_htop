#include "system/status/system_status.h"

SystemStatus::SystemStatus(
    const std::shared_ptr<OperatingSystemStatus> operating_system_status_
    ) : operating_system_status(operating_system_status_) {

};

const std::shared_ptr<OperatingSystemStatus> SystemStatus::OperatingSystem(){
    return operating_system_status;
}

// ProcessorsStatus *processors_status,