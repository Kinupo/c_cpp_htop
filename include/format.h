#ifndef FORMAT_H
#define FORMAT_H

#include <string>
#include <sstream>

namespace Format {
    const int kSecondsInMinute = 60;
    const int kSecondsInHour = 3600;

    const int kHours = 0;
    const int kMinutes = 1;
    const int kSeconds = 2;

    bool ShouldLeftPad(const int duration);
    std::string FormatTime(const int time[3]);
    std::string ElapsedTime(long times);  // TODO: See src/format.cpp
};                                    // namespace Format

#endif