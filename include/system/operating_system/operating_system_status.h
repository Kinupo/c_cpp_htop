#ifndef OPERATING_SYSTEM_STATUS_H
#define OPERATING_SYSTEM_STATUS_H

#include <string>

class OperatingSystemStatus{
  private:
    const std::string name;
    const std::string kernal_version;

  public:
    OperatingSystemStatus(
        const std::string name, 
        const std::string kernal_version);

    const std::string Name();
    const std::string KernalVersion();
};


#endif