#include "format.h"

bool Format::ShouldLeftPad(const int duration){
    return duration < 10;
};

std::string Format::FormatTime(const int time[3]){
    
    std::ostringstream time_stream;

    for(int i = 0; i < 3; i++){
        if(ShouldLeftPad(time[i]))
            time_stream <<  "0";
        time_stream << time[i];
        if(i<2)
            time_stream << ":";
    }

    return time_stream.str();
};

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
std::string Format::ElapsedTime(const long total_seconds) { 
    
    int time[3];

    time[kHours] = total_seconds/kSecondsInHour;
    time[kSeconds] = total_seconds - (time[kHours] * kSecondsInHour);
    time[kMinutes] = time[kSeconds]/kSecondsInMinute;
    time[kSeconds] = time[kSeconds] - (time[kMinutes] * kSecondsInMinute);

    return FormatTime(time);
}