//
// Advent of Code - 2022
// https://adventofcode.com/2022
// Created by Pedro Alves
//

#include "aoc_2022.h"
#include "aoc_utils.h"

#include <iostream>
#include <utility>
#include <set>

Solution AOC_2022::day6_solve() {
    std::vector<std::string> input = read_file("input/2022/Day_6.txt");
    std::cout << "Day 6 - 2022:" << std::endl;
    Solution solution = {"Not implemented", "Not implemented", 0};

    solution.part1 = std::to_string(day_6_find_marker_pos(input[0], 4));
    solution.part2 = std::to_string(day_6_find_marker_pos(input[0], 14));

    return solution;
}

int AOC_2022::day_6_find_marker_pos(const std::string &input, int seq_size) {
    int pos = 0;

    while (pos != input.length() - (seq_size - 1)) {
        // Use a set since we want to check that the full 4 character sequence has different characters
        std::set<char> seq;
        for (int i = pos; i < pos + seq_size; i++) {
            seq.insert(input.at(i));
        }
        if(seq.size() == seq_size) {
            // The marker is at the end of the sequence, thus add 4
            return pos + seq_size;
        }

        pos++;
    }

    return 0;
}
