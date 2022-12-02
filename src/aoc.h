//
// Advent of Code
// https://adventofcode.com/
// Created by Pedro Alves
//

#ifndef ADVENT_OF_CODE_AOC_H
#define ADVENT_OF_CODE_AOC_H

#include "aoc_types.h"
#include "sols/2022/aoc_2022.h"

class AOC {
    AOC_2022 aoc_2022;
public:
    AOC() : aoc_2022() {}

    Solution solve(int year, int day);
};

#endif //ADVENT_OF_CODE_AOC_H