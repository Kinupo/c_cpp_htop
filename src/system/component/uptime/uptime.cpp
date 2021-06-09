#include "system/component/uptime/uptime.h"

Uptime::Uptime(const float uptime):uptime_(uptime){};
ComponentType Uptime::Component(){return component_type_;}
float Uptime::Seconds(){return uptime_;}