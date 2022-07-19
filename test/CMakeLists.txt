add_executable(kernel-config-test kernel-config-parser-test.cpp)
target_link_libraries(kernel-config-test kernel-config-parser)

set(TEST_DIRECTORY "\"${CMAKE_CURRENT_SOURCE_DIR}\"")

target_compile_definitions(kernel-config-test PRIVATE TEST_DIR=${TEST_DIRECTORY})