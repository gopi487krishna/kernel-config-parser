#pragma once

#include <string>
#include <unordered_map>

namespace kconfig
{
    class ConfigParser
    {
    public:
        /**
         * @brief Construct a new Config Parser object
         *
         * @param filename Path to the .config file containing the kernel configuration
         */
        ConfigParser(const std::string &filename);

        /**
         * @brief Checks if the option is available inside .config file
         *
         * @param option Option to be checked
         */
        bool contains(const std::string &option);

        /**
         * @brief Returns the value of option passed as an argument to the operator
         *
         * @param option Option whose value needs to be obtained
         * @return std::string Value of the option or empty string if option not exist
         */
        std::string operator[](const std::string &option);

    private:
        std::unordered_map<std::string, std::string> m_option_values;
    };
}
