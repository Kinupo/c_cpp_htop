#include "processor.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {return utilization_;}

void Processor::Utilization(const float utilization){
    utilization_ = utilization;
}