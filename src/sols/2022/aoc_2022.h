//
// Created by pedro on 01/12/22.
//

#ifndef ADVENT_OF_CODE_AOC_2022_H
#define ADVENT_OF_CODE_AOC_2022_H

#include <map>
#include <functional>

#include "aoc_types.h"
#include "files.h"

class AOC_2022 {
    std::map<int, std::function<Solution()>> solutions;

    static Solution day1_solve();
public:
    AOC_2022();
    Solution solve(int day);

    // ----------------------------------------- DAY 1 -----------------------------------------

    /**
     * Calculates the amount of calories brought by each elf
     *
     * @param meals A list of all meals brought by the elves
     * @return A list of each elf's calories brought
     */
    static std::vector<int> aggregate_calories(const std::vector<std::string>  &meals);

    /**
     * Gets a sum of the calorie meal total for the 3 elves with the most calories brought
     *
     * @param calories A list of each elf's calories brought
     * @return The total calorie total brought by the elves with the top 3 caloric meals
     */
    static int calculate_top_three(std::vector<int> &calories);
};

#endif //ADVENT_OF_CODE_AOC_2022_H
