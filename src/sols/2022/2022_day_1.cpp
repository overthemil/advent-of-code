//
// Advent of Code - 2022
// https://adventofcode.com/2022
// Created by Pedro Alves
//

#include "aoc_2022.h"
#include "aoc_utils.h"

#include <iostream>

Solution AOC_2022::day1_solve() {
    std::vector<std::string> input = read_file("input/2022/Day_1.txt");
    std::cout << "Day 1 - 2022:" << std::endl;
    Solution solution = {"Not implemented", "Not implemented", 0};

    auto calories = day_1_aggregate_calories(input);
    int max_calories = *std::max_element(calories.begin(), calories.end());
    solution.part1 = std::to_string(max_calories);

    auto top_calories = day_1_calculate_top_three(calories);
    solution.part2 = std::to_string(top_calories);

    return solution;
}

std::vector<int> AOC_2022::day_1_aggregate_calories(const std::vector<std::string> &meals) {
    std::vector<int> calories;

    int meal_calories = 0;
    for (const auto &meal: meals) {
        if (meal.empty()) {
            // Empty line therefore the total calories for the elf
            calories.push_back(meal_calories);
            meal_calories = 0;
        } else {
            meal_calories += stoi(meal);
        }
    }
    // We always need to add the last elf's meals' calories since there's no newline at the end of the file
    calories.push_back(meal_calories);

    return calories;
}

int AOC_2022::day_1_calculate_top_three(std::vector<int> &calories) {
    std::sort(calories.begin(), calories.end(), std::greater<>());

    int top_calories = 0;
    if (calories.size() >= 3) {
        for (int i = 0; i < 3; i++) {
            top_calories += calories[i];
        }
    }

    return top_calories;
}