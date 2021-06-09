#include "parser/delimited_parser.h"

std::string DelimitedParser::Trim(const std::string string_to_trim){
    return string_to_trim.substr(string_to_trim.find_first_not_of(" \t"));
}

std::unique_ptr<std::vector<std::string>> DelimitedParser::ParseLine(
        const std::string line, 
        const char delimiter){
     
    std::stringstream stream_to_parse(line);
    
    auto parsed_strings = std::unique_ptr<std::vector<std::string>>(new std::vector<std::string>);
    while(stream_to_parse.good()) {
        std::string parsed_string;
        getline(stream_to_parse, parsed_string, delimiter);
        parsed_strings->push_back(parsed_string);
    }

    return parsed_strings;
}

std::unique_ptr<std::vector<std::string>> DelimitedParser::ParseTrimKey(
    const std::string key, 
    const std::string unparsed_string,
    const char delimiter){
    auto trimmed_string = Trim(unparsed_string.substr(unparsed_string.find_first_not_of(key)));
    return ParseLine(trimmed_string, delimiter); 
}