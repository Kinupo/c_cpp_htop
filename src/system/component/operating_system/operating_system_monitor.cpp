#include "system/component/operating_system/operating_system_monitor.h"

OperatingSystemMonitor::OperatingSystemMonitor(){}

std::shared_ptr<ComponentStatus> OperatingSystemMonitor::Status(){
    return Status(nullptr);
}

std::string OperatingSystemMonitor::FindVersion(){
    std::string version;
    auto unparsed_version = FileReader::ReadAllLines(kVersionFilename);
    if((*unparsed_version).size() > 0){
        auto parsed_version = DelimitedParser::ParseLine((*unparsed_version).at(0), ' ');
        if((*parsed_version).size() > 3)
            version = (*parsed_version).at(2);
    }
    return version;
}

std::string OperatingSystemMonitor::FindOsName(){
    
    std::string pretty_name;

    auto os_properties = FileReader::ReadLines(kOsPath, os_keys);
    auto unparsed_os = (*os_properties).find("PRETTY_NAME");

    if(unparsed_os != (*os_properties).end()){
        auto parsed_os = DelimitedParser::ParseLine(unparsed_os->second, '=');
        if((*parsed_os).size() > 1)
            pretty_name = (*parsed_os).at(1);
        if(pretty_name.length() > 2)//remove quotes
            pretty_name = pretty_name.substr(1, pretty_name.length() -2);
    } 
    return pretty_name;
}

std::shared_ptr<ComponentStatus> OperatingSystemMonitor::Status(
    std::shared_ptr<ComponentStatus> prior_status){
    
    std::string version = FindVersion();
    std::string pretty_name = FindOsName();

    return std::make_shared<OperatingSystemStatus>(pretty_name, version);
}

ComponentType OperatingSystemMonitor::ComponentMonitored(){return component_type_;} 