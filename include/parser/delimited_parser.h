#ifndef _PARSER_DELIMITED_PARSER_H_
#define _PARSER_DELIMITED_PARSER_H_

#include <sstream>
#include <memory>
#include <string>
#include <vector>

namespace DelimitedParser {
    std::unique_ptr<std::vector<std::string>> ParseLine(
        const std::string line, 
        const char delimiter);
    std::unique_ptr<std::vector<std::string>> ParseTrimKey(
        const std::string key, 
        const std::string unparsed_string,
        const char delimiter);
    std::string Trim(const std::string string_to_trim);
};

#endif