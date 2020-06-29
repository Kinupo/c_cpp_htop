#ifndef COMPONENT_STATUS_H
#define COMPONENT_STATUS_H

#include "system/component/component_type.h"
//Interface for componet status
class ComponentStatus{
    public:
        virtual const ComponentType Component() = 0;
};

#endif