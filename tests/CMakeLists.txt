#include_directories(/opt/cpputest/include) #include header source for CppUTest
find_package(CppUTest REQUIRED)
add_library(unit_test_core test_main.cpp)
add_executable(DemoTests 
    unit_tests.cpp
    ${CMAKE_SOURCE_DIR}/src/worker.cpp)
target_link_libraries(DemoTests unit_test_core CppUTest CppUTestExt)
add_test(NAME DemoTests COMMAND DemoTests)