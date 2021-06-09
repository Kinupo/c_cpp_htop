#ifndef _SYSTEM_UP_TIME_UP_TIME_SERVICE_
#define _SYSTEM_UP_TIME_UP_TIME_SERVICE_

#include <string>

#include "file_reader/file_reader.h"
#include "parser/delimited_parser.h"

namespace UpTimeService{

    const std::string kUpTimeFilePath = "/proc/uptime";
    int CurrentUpTime();

};

#endif