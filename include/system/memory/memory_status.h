#ifndef MEMORY_STATUS_H
#define MEMORY_STATUS_H

class MemoryStatus {
    private:
        const int total;
        const int used;
    public:
        MemoryStatus(const int total, const int used);
        //as percentage 
        const float Utilization();
};

#endif