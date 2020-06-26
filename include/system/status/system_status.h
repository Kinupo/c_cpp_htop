#ifndef SYSTEM_STATUS_H
#define SYSTEM_STATUS_H

// #include "system/cpu/processors_status.h"
#include "system/operating_system/operating_system_status.h"
#include <memory>

class SystemStatus{
    private:
        // const ProcessorsStatus *processors_status;
        const std::shared_ptr<OperatingSystemStatus> operating_system_status;
    public:
        SystemStatus(const std::shared_ptr<OperatingSystemStatus> operating_system_status);

        const std::shared_ptr<OperatingSystemStatus> OperatingSystem();
};

#endif

            // ProcessorsStatus *processors_status,