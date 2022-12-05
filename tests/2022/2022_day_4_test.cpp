#include <gtest/gtest.h>
#include "sols/2022/aoc_2022.h"

TEST(Day4_2022_Test, SplitAssignment) {
    std::string input = "2-4,6-8";

    std::pair<std::string,std::string> expected = {
            "2-4",
            "6-8"
    };

    EXPECT_EQ(AOC_2022::day_4_split_assignments(input), expected);
}

TEST(Day4_2022_Test, GetRange) {
    std::string input = "6-8";

    std::vector<int> expected = {6, 7, 8};

    EXPECT_EQ(AOC_2022::day_4_get_range(input), expected);

    std::string input2 = "92-101";

    std::vector<int> expected2 = {92, 93, 94, 95, 96, 97, 98, 99, 100, 101};

    EXPECT_EQ(AOC_2022::day_4_get_range(input2), expected2);
}

TEST(Day4_2022_Test, CountFullyContained) {
    std::vector<std::string> input = {
            "2-8,3-7",
            "6-6,4-6",
            "1-20,50-55"
    };

    EXPECT_EQ(AOC_2022::day_4_fully_contained_ranges(input), 2);
}

TEST(Day4_2022_Test, CountOverlapping) {
    std::vector<std::string> input = {
            "2-8,3-7",
            "6-6,4-6",
            "1-20,50-55",
            "1-5,2-8",
            "4-40,39-100",
            "1-10,11-20"
    };

    EXPECT_EQ(AOC_2022::day_4_intersecting_ranges(input), 4);
}