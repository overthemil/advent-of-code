#include <gtest/gtest.h>
#include "sols/2022/aoc_2022.h"

TEST(Day3_2022_Test, FindCompartmentItems) {
    std::string input = "vJrwpWtwJgWrhcsFMMfFFhFp";

    std::vector<std::string> expected = {
            "vJrwpWtwJgWr",
            "hcsFMMfFFhFp"
    };

    EXPECT_EQ(AOC_2022::day_3_find_compartment_items(input), expected);
}

TEST(Day3_2022_Test, FindCommonItem) {
    std::vector<std::string> input = {
            "vJrwpWtwJgWr",
            "hcsFMMfFFhFp"
    };
    std::vector<char> expected = {'p'};

    EXPECT_EQ(AOC_2022::day_3_find_common_item(input), expected);
}

TEST(Day3_2022_Test, FindItemPriority) {
    EXPECT_EQ(AOC_2022::day_3_find_item_priority('a'), 1);
    EXPECT_EQ(AOC_2022::day_3_find_item_priority('z'), 26);
    EXPECT_EQ(AOC_2022::day_3_find_item_priority('A'), 27);
    EXPECT_EQ(AOC_2022::day_3_find_item_priority('Z'), 52);
}

TEST(Day3_2022_Test, FindTotalPriorityBackpacks) {
    std::vector<std::string> input = {
            "vJrwpWtwJgWrhcsFMMfFFhFp",
            "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL",
            "PmmdzqPrVvPwwTWBwg",
            "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn",
            "ttgJtRGJQctTZtZT",
            "CrZsJsPPZsGzwwsLwLmpwMDw"
    };

    EXPECT_EQ(AOC_2022::day_3_find_total_priority_of_rucksacks(input), 157);
}

TEST(Day3_2022_Test, FindTotalPriorityBadges) {
    std::vector<std::string> input = {
            "vJrwpWtwJgWrhcsFMMfFFhFp",
            "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL",
            "PmmdzqPrVvPwwTWBwg",
            "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn",
            "ttgJtRGJQctTZtZT",
            "CrZsJsPPZsGzwwsLwLmpwMDw"
    };

    EXPECT_EQ(AOC_2022::day_3_find_total_priority_of_badges(input), 70);
}

TEST(Day3_2022_Test, FindBadgeOfGroup) {
    std::vector<std::string> group_1_input = {
            "vJrwpWtwJgWrhcsFMMfFFhFp",
            "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL",
            "PmmdzqPrVvPwwTWBwg",
    };

    EXPECT_EQ(AOC_2022::day_3_find_group_badge(group_1_input), 'r');

    std::vector<std::string> group_2_input = {
            "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn",
            "ttgJtRGJQctTZtZT",
            "CrZsJsPPZsGzwwsLwLmpwMDw"
    };

    EXPECT_EQ(AOC_2022::day_3_find_group_badge(group_2_input), 'Z');
}