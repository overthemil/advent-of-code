cmake_minimum_required(VERSION 3.22)
project(advent_of_code)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(advent_of_code_tests 2022/2022_day_1_test.cpp 2022/2022_day_2_test.cpp 2022/2022_day_3_test.cpp 2022/2022_day_4_test.cpp 2022/2022_day_5_test.cpp)
target_include_directories(advent_of_code_tests PRIVATE ../src/)
target_link_libraries(
        advent_of_code_tests
        GTest::gtest
        GTest::gtest_main
        advent_of_code_lib
)

include(GoogleTest)
gtest_discover_tests(advent_of_code_tests)