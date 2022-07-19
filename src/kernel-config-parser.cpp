
#include <fstream>
#include <iostream>
#include "kernel-config-parser.hpp"

kconfig::ConfigParser::ConfigParser(const std::string &filename)
{
    std::ifstream config_file(filename);
    if (!config_file.is_open())
    {
        std::cerr << "Config Parser: Failed to open file : " << filename << "\n";
        std::abort();
    }

    std::uint64_t current_line_number = 0;

    for (std::string line; getline(config_file, line); ++current_line_number)
    {
        // TODO : Check for spaces in future
        if (line[0] == 'C')
        {
            auto equals_position = line.find('=');
            if (equals_position == std::string::npos)
            {
                std::cerr << "Config Parser: Invalid config - Check Line : " << current_line_number << "\n";
            }

            // Generate key value pair
            std::string option(line.begin(), line.begin() + equals_position);
            std::string value(line.begin() + equals_position + 1, line.end());

            
            // Removing quotes from string if there
            if (value == "\"\"") value.clear(); // Empty String
            if (value[0]=='\"') value = std::string(value.begin()+1, value.end()-1);

            m_option_values.insert({option, value});
        }
        else
        {
            // If hash or space or anything else

            continue;
        }
    }
}

bool kconfig::ConfigParser::contains(const std::string &option)
{
    return m_option_values.find(option) != m_option_values.end();
}

std::string kconfig::ConfigParser::operator[](const std::string &option)
{
    return m_option_values[option];
}