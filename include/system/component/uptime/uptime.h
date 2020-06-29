#ifndef UPTIME_H
#define UPTIME_H

#include "system/component/component_status.h"

class Uptime : public ComponentStatus{
    private:
        const float uptime;
        const ComponentType componentType = kUptime;
    public:
        Uptime(const float uptime);
        const ComponentType Component();
};

#endif