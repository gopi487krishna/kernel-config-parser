

#include "kernel-config-parser.hpp"

kconfig::ConfigParser::ConfigParser(const std::string &filename)
{
    
}

bool kconfig::ConfigParser::contains(const std::string &option)
{
    return m_option_values.find(option) != m_option_values.end();
}

std::string kconfig::ConfigParser::operator[](const std::string &option)
{
    return m_option_values[option];
}