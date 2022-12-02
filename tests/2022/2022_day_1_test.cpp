#include <gtest/gtest.h>
#include "sols/2022/aoc_2022.h"

TEST(Day1_2022_Test, CalculatesEveryoneTotalCalories) {
    std::vector<std::string> input = {
            "1",
            "1",
            "3",
            "",
            "4",
            "",
            "5",
            "4"
    };

    std::vector<int> expected = {
            5,
            4,
            9
    };
    std::vector<int> calories = AOC_2022::aggregate_calories(input);

    EXPECT_EQ(calories, expected);
}

TEST(Day1_2022_Test, CalculatesTopThreeCalories) {
    std::vector<int> input = {
            2,
            40,
            3,
            5,
            10,
            15
    };

    int expected = 65;
    int calories = AOC_2022::calculate_top_three(input);

    EXPECT_EQ(calories, expected);
}