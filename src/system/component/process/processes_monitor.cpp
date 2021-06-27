#include "system/component/process/processes_monitor.h"

bool ProcessesMonitor::isNumber(std::string string){
    bool isNumber = false;
    try{
        std::stoi(string);
        isNumber = true;
    } catch (const std::invalid_argument& e){}
    return isNumber;
}

int ProcessesMonitor::ParseUid(const std::string unparsed_status){
    auto parsed_uid = DelimitedParser::ParseTrimKey(kKeyUid, unparsed_status, ' ');
    if(parsed_uid->size() > 0)
        return std::stoi(parsed_uid->at(0));
    return 0;
}

float ProcessesMonitor::ParseMemoryUsage(const std::string unparsed_status){
    auto parsed_memory = DelimitedParser::ParseTrimKey(kKeyMemoryUsage, unparsed_status, ' ');
    float memory = 0.0;
    try {
        if(parsed_memory->size() > 0)
            memory = std::stof(parsed_memory->at(0))/kKbInMb;
    } catch (std::invalid_argument e) {}
    return memory;
}

void ProcessesMonitor::FindProcessTimes(
    const std::string process_path, 
    const int system_up_time, 
    int process_times[2]){

    auto unparsed_stat = FileReader::ReadAllLines(process_path + kProcessStatPath);
    if(unparsed_stat->size() > 0){
        auto parsed_stat = DelimitedParser::ParseLine(unparsed_stat->at(0), ' ');
        if(parsed_stat->size() > 22){
            auto start_time = std::stoi(parsed_stat->at(kColumnStartTime));
            auto user_time = std::stoi(parsed_stat->at(kColumnUserTime));
            auto system_time = std::stoi(parsed_stat->at(kColumnSystemTime));

            auto total_time = user_time + system_time;
            auto process_up_time = system_up_time - (start_time/kTicksPerSecond);

            process_times[0] = process_up_time;
            process_times[1] = total_time;
        }
    }
}

std::shared_ptr<ProcessStatus> ProcessesMonitor::FindProcessDetails(
    const std::string process,
    const int system_up_time){
    
    const std::string process_path = kProcPath + "/" + process; 
    auto unparsed_status 
        = FileReader::ReadLines(process_path + kProcessStatusPath, process_keys_);
    
    auto raw_cmd = FileReader::ReadAllLines(process_path + kProcessCommandPath);
    auto cmd = raw_cmd->size() > 0 ? raw_cmd->at(0): "";

    int process_times[2];
    FindProcessTimes(process_path, system_up_time,  process_times);
    auto cpu_utilization = (((float)(process_times[1]/(float)kTicksPerSecond)/((float)process_times[0])));

    return std::make_shared<ProcessStatus>(
        std::stoi(process), 
        cmd, 
        ParseUid((*unparsed_status)[kKeyUid]), 
        cpu_utilization,
        ParseMemoryUsage((*unparsed_status)[kKeyMemoryUsage]), 
        process_times[0]);
}

std::shared_ptr<std::vector<std::string>> ProcessesMonitor::FindActiveProcessDirectories(){
    
    std::shared_ptr<std::vector<std::string>> process_directories 
        = std::make_shared<std::vector<std::string>>();
    #if __cplusplus == 201703L
        auto directory_listing = std::filesystem::directory_iterator(kProcPath);
    #else
        auto directory_listing = std::experimental::filesystem::directory_iterator(kProcPath);
    #endif
    for(auto directory:directory_listing){
        auto directory_name = directory.path().filename();
        if(
            #if __cplusplus == 201703L
                directory.is_directory() &&
            #endif
            isNumber(directory.path().filename()))
            process_directories->push_back(directory.path().filename());
    }
    return process_directories;
}

std::shared_ptr<ComponentStatus> ProcessesMonitor::Status(){

    std::vector<std::shared_ptr<ProcessStatus>> processes;
    
    auto up_time = UpTimeService::CurrentUpTime();

    auto process_directories = FindActiveProcessDirectories();
    for(auto proc:*process_directories){
        try {
            auto procss = FindProcessDetails(proc, up_time);
            processes.push_back(procss);
        } catch(std::runtime_error e){//skip error if the process has ended before processing
            if(std::string(e.what()).find("could not be oppened by FileReader") == std::string::npos)
                throw e;
        }
    }

    auto unparsed_process_counts = FileReader::ReadLines(kProcStatPath, keys_);
    auto num_running_processes_parsed = DelimitedParser::ParseLine(
                                    (*unparsed_process_counts)[kKeyRunningProcesses], 
                                    ' ');
    auto num_total_processes_parsed = DelimitedParser::ParseLine(
                                    (*unparsed_process_counts)[kKeyTotalProcesses], 
                                    ' ');

    return std::make_shared<ProcessesStatus>(
        std::stoi((*num_total_processes_parsed).at(1)), 
        std::stoi((*num_running_processes_parsed).at(1)), 
        processes);
}

std::shared_ptr<ComponentStatus> ProcessesMonitor::Status(
    std::shared_ptr<ComponentStatus> prior_status){
    return Status();
}

ComponentType ProcessesMonitor::ComponentMonitored(){return component_type_;}