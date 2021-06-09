#include "system/up_time/up_time_service.h"

int UpTimeService::CurrentUpTime(){
    auto unparsed_up_time = FileReader::ReadAllLines(kUpTimeFilePath);
    auto parsed_up_time = DelimitedParser::ParseLine((*unparsed_up_time).at(0), ' ');
    return std::stoi((*parsed_up_time).at(0));
}