#include "kernel-config-parser.hpp"
#include <iostream>

int main()
{

    kconfig::ConfigParser config_parser(TEST_DIR "/sample-config");

    std::string test_value1 = config_parser["CONFIG_LOCALVERSION"];
    std::string test_value2 = config_parser["CONFIG_DEFAULT_HOSTNAME"];
    std::string test_value3 = config_parser["CONFIG_HAVE_ARCH_AUDITSYSCALL"];

    if (
        !test_value1.empty() ||
        test_value2 != "(none)" ||
        test_value3 != "y")
    {
        std::cerr << "Test failed\n";
        return 1;
    }

    std::cout << "Tests Passed\n";

    return 0;
}