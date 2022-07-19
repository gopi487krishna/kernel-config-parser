
# Kernel Config Parser

Simple library to parse .config file for the linux kernel and expose the options via a simple API
 

## Authors

- [@Gopi Krishna Menon](https://github.com/gopi487krishna)


## Usage/Examples

Source File : [test/kernel-config-parser-test.cpp](https://github.com/gopi487krishna/kernel-config-parser/blob/25639b8c9bc63deacf8a067c621ed9f9a87284e4/test/kernel-config-parser-test.cpp)
CMake config :[test/CMakeLists.txt](https://github.com/gopi487krishna/kernel-config-parser/blob/25639b8c9bc63deacf8a067c621ed9f9a87284e4/test/CMakeLists.txt)
```cpp
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
```


