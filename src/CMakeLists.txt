cmake_minimum_required(VERSION 3.22)
project(advent_of_code)

set(CMAKE_CXX_STANDARD 20)
file(COPY ../input DESTINATION .)

add_executable(advent_of_code main.cpp aoc.h aoc.cpp utils/files.cpp sols/2022/aoc_2022.h sols/2022/aoc_2022.cpp utils/aoc_utils.cpp ../include/aoc_utils.h sols/2022/2022_day_1.cpp sols/2022/2022_day_2.cpp sols/2022/2022_day_3.cpp sols/2022/2022_day_4.cpp)
target_include_directories(advent_of_code PRIVATE ../include/)

add_library(advent_of_code_lib main.cpp aoc.h aoc.cpp utils/files.cpp sols/2022/aoc_2022.h sols/2022/aoc_2022.cpp utils/aoc_utils.cpp ../include/aoc_utils.h sols/2022/2022_day_1.cpp sols/2022/2022_day_2.cpp sols/2022/2022_day_3.cpp sols/2022/2022_day_4.cpp)
target_include_directories(advent_of_code_lib PUBLIC ../include/)