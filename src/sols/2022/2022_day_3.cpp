//
// Advent of Code - 2022
// https://adventofcode.com/2022
// Created by Pedro Alves
//

#include "aoc_2022.h"
#include "aoc_utils.h"

#include <iostream>

Solution AOC_2022::day3_solve() {
    std::vector<std::string> input = read_file("input/2022/Day_3.txt");
    std::cout << "Day 3 - 2022:" << std::endl;
    Solution solution = {"Not implemented", "Not implemented", 0};

    solution.part1 = std::to_string(day_3_find_total_priority_of_rucksacks(input));
    solution.part2 = std::to_string(day_3_find_total_priority_of_badges(input));

    return solution;
}

std::vector<std::string> AOC_2022::day_3_find_compartment_items(const std::string &backpack) {
    std::vector<std::string> compartments;

    auto midpoint = backpack.length() / 2;
    compartments.push_back(backpack.substr(0, midpoint));
    compartments.push_back(backpack.substr(midpoint, midpoint));

    return compartments;
}

std::vector<char> AOC_2022::day_3_find_common_item(const std::vector<std::string> &compartments) {
    std::vector<char> common_items;
    for (const auto &item: compartments[0]) {
        if (compartments[1].find(item) != std::string::npos) {
            common_items.push_back(item);
        }
    }

    return common_items;
}

int AOC_2022::day_3_find_item_priority(char item) {
    const std::string priorities = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    return static_cast<int>(priorities.find(item)) + 1;
}

int AOC_2022::day_3_find_total_priority_of_rucksacks(const std::vector<std::string> &backpacks) {
    int priority = 0;

    for (const auto &backpack: backpacks) {
        const auto compartments = day_3_find_compartment_items(backpack);
        auto common_items = day_3_find_common_item(compartments);
        // Assume there is only one common item for Part 1
        priority += day_3_find_item_priority(common_items[0]);
    }
    return priority;
}


int AOC_2022::day_3_find_total_priority_of_badges(const std::vector<std::string> &backpacks) {
    int total_priority = 0;

    // Iterate through each group
    for (int i = 0; i < backpacks.size(); i += 3) {
        std::vector<std::string> group(backpacks.begin() + i, backpacks.begin() + i + 3);
        char badge = day_3_find_group_badge(group);
        total_priority += day_3_find_item_priority(badge);
    }

    return total_priority;
}

char AOC_2022::day_3_find_group_badge(const std::vector<std::string> &groups) {
    // Probably should use a Set here but this seems quick and easy enough for this scenario
    std::vector<char> common_items_1_2;
    // Find the common items in Backpack 1 and 2
    for (const auto &item: groups[0]) {
        if (groups[1].find(item) != std::string::npos) {
            common_items_1_2.push_back(item);
        }
    }

    // Find the common items in all three backpacks
    std::vector<char> common_items;
    for (const auto &item: common_items_1_2) {
        if (groups[2].find(item) != std::string::npos) {
            common_items.push_back(item);
        }
    }

    // Assume only one common item per group as the badge can only be one item
    return common_items[0];
}

