cmake_minimum_required(VERSION 3.21)

project(DemoTemplate)
set(CMAKE_CXX_STANDARD 20)

# Check the BUILD_TESTING variable to determine which directory to add
if(PROD_BUILD)
    add_subdirectory(src)
else()
    enable_testing()
    add_subdirectory(tests)
endif()
