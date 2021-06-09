#ifndef UPTIME_H
#define UPTIME_H

#include "system/component/component_status.h"

class Uptime : public ComponentStatus{
    private:
        const float uptime_;
        const ComponentType component_type_ = kUptime;
    public:
        Uptime(const float uptime);
        ComponentType Component();
        float Seconds();
};

#endif