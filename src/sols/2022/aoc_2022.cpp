//
// Advent of Code - 2022
// https://adventofcode.com/2022
// Created by Pedro Alves
//

#include "aoc_2022.h"
#include "aoc_utils.h"

#include <iostream>

AOC_2022::AOC_2022() {
    solutions = {
            {1, []() { return day1_solve(); }},
            {2, []() { return day2_solve(); }},
            {3, []() { return day3_solve(); }}
    };
}

Solution AOC_2022::solve(int day) {
    return solutions[day]();
}
