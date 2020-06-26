#ifndef STATUS_MONITOR_H
#define STATUS_MONITOR_H

template <typename T>
class StatusMonitor{
    public:
        virtual T Status() = 0;
        virtual T Status(T prior_status) = 0;
};

#endif