
#include <iostream>

#include "aoc.h"

int main() {
    AOC aoc;
    Solution solution;
    solution = aoc.solve(2022, 4);
    std::cout << "\tPart 1 - " << solution.part1 << std::endl;
    std::cout << "\tPart 2 - " << solution.part2 << std::endl;
    std::cout << "\tTime Taken - " << solution.time_taken << " us" << std::endl;
    return 0;
}