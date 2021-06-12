#include "parser/delimited_parser.h"

std::string DelimitedParser::Trim(const std::string &string_to_trim){
    auto value_start =  string_to_trim.find_first_not_of(" \t");
        if(value_start == std::string::npos)
            value_start = 0;
    return string_to_trim.substr(value_start);
}

std::unique_ptr<std::vector<std::string>> DelimitedParser::ParseLine(
        const std::string &line, 
        const char &delimiter){
     
    std::stringstream stream_to_parse(line);
    
    auto parsed_strings = std::make_unique<std::vector<std::string>>();
    while(stream_to_parse.good()) {
        std::string parsed_string;
        getline(stream_to_parse, parsed_string, delimiter);
        parsed_strings->push_back(parsed_string);
    }

    return parsed_strings;
}

std::unique_ptr<std::vector<std::string>> DelimitedParser::ParseTrimKey(
    const std::string &key, 
    const std::string &unparsed_string,
    const char &delimiter){
    
    auto value_start = unparsed_string.find_first_not_of(key);
    if(value_start != std::string::npos)
       return ParseLine(Trim(unparsed_string.substr(value_start)), delimiter);
    return ParseLine(unparsed_string, delimiter); 
}