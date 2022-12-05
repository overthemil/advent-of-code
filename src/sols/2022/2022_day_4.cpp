//
// Advent of Code - 2022
// https://adventofcode.com/2022
// Created by Pedro Alves
//

#include "aoc_2022.h"
#include "aoc_utils.h"

#include <iostream>
#include <set>

Solution AOC_2022::day4_solve() {
    std::vector<std::string> input = read_file("input/2022/Day_4.txt");
    std::cout << "Day 4 - 2022:" << std::endl;
    Solution solution = {"Not implemented", "Not implemented", 0};

    solution.part1 = std::to_string(day_4_fully_contained_ranges(input));
    solution.part2 = std::to_string(day_4_intersecting_ranges(input));

    return solution;
}


std::pair<std::string, std::string> AOC_2022::day_4_split_assignments(const std::string &assignment) {
    auto s = split(assignment, ",");
    std::pair<std::string, std::string> assignment_split(s[0], s[1]);
    return assignment_split;
}

std::vector<int> AOC_2022::day_4_get_range(const std::string &assignment) {
    std::vector<int> range;

    auto limits_str = split(assignment, "-");
    int lower_lim = std::stoi(limits_str[0]);
    int upper_lim = std::stoi(limits_str[1]);

    for(int i = lower_lim; i <= upper_lim; i++) {
        range.push_back(i);
    }

    return range;
}

int AOC_2022::day_4_fully_contained_ranges(const std::vector<std::string> &assignments) {
    int count = 0;

    for(const auto &assignment : assignments) {
        auto pair = day_4_split_assignments(assignment);

        std::set<int> range_num;

        // Add all ranges from the first pair
        auto range_1 = day_4_get_range(pair.first);
        for(const auto &n : range_1) {
            range_num.insert(n);
        }
        // Add all ranges from the second pair
        auto range_2 = day_4_get_range(pair.second);
        for(const auto &n : range_2) {
            range_num.insert(n);
        }

        // Check if any range are fully contained
        if(range_num.size() == range_1.size() || range_num.size() == range_2.size()) {
            count++;
        }
    }

    return count;
}

int AOC_2022::day_4_intersecting_ranges(const std::vector<std::string> &assignments) {
    int count = 0;

    for(const auto &assignment : assignments) {
        auto pair = day_4_split_assignments(assignment);

        std::set<int> range_num;

        // Add all ranges from the first pair
        auto range_1 = day_4_get_range(pair.first);
        for(const auto &n : range_1) {
            range_num.insert(n);
        }
        // Add all ranges from the second pair
        auto range_2 = day_4_get_range(pair.second);
        for(const auto &n : range_2) {
            range_num.insert(n);
        }

        // Check if any ranges overlap
        if(range_num.size() != (range_1.size() + range_2.size())) {
            count++;
        }
    }

    return count;
}