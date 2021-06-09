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
    return std::stoi((*parsed_uid).at(0));
}

float ProcessesMonitor::ParseMemoryUsage(const std::string unparsed_status){
    auto parsed_memory = DelimitedParser::ParseTrimKey(kKeyMemoryUsage, unparsed_status, ' ');
    return std::stof((*parsed_memory).at(0))/kKbInMb;
}

std::shared_ptr<ProcessStatus> ProcessesMonitor::FindProcessDetails(
    const std::string process,
    const int system_up_time){
    
    const std::string process_path = kProcPath + "/" + process; 
    auto unparsed_status 
        = FileReader::ReadLines(process_path + kProcessStatusPath, process_keys_);
    
    auto unparsed_stat = FileReader::ReadAllLines(process_path + kProcessStatPath);
    auto parsed_stat = DelimitedParser::ParseLine(unparsed_stat->at(0), ' ');
    
    auto start_time = std::stoi(parsed_stat->at(kColumnStartTime));
    auto user_time = std::stoi(parsed_stat->at(kColumnUserTime));
    auto system_time = std::stoi(parsed_stat->at(kColumnSystemTime));

    auto total_time = user_time + system_time;
    auto process_up_time = system_up_time - (start_time/kTicksPerSecond);

    return std::make_shared<ProcessStatus>(
        std::stoi(process), 
        FileReader::ReadAllLines(process_path +  kProcessCommandPath).get()->at(0), 
        ParseUid((*unparsed_status)[kKeyUid]), 
        (((float)(total_time/(float)kTicksPerSecond)/((float)process_up_time))),
        ParseMemoryUsage((*unparsed_status)[kKeyMemoryUsage]), 
        process_up_time);
}

std::shared_ptr<std::vector<std::string>> ProcessesMonitor::FindActiveProcessDirectories(){
    
    std::shared_ptr<std::vector<std::string>> process_directories 
        = std::make_shared<std::vector<std::string>>();
    auto directory_listing = std::filesystem::directory_iterator(kProcPath);
    for(auto directory:directory_listing){
        auto directory_name = directory.path().filename();
        if(directory.is_directory() && isNumber(directory.path().filename()))
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