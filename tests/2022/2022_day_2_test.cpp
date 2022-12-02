#include <gtest/gtest.h>
#include "sols/2022/aoc_2022.h"

TEST(Day2_2022_Test, CalculatePlayChoiceScore) {
    // Rock is worth 1 point
    EXPECT_EQ(AOC_2022::rps_your_score("X"), 1);
    // Paper is worth 2 points
    EXPECT_EQ(AOC_2022::rps_your_score("Y"), 2);
    // Scissor is worth 3 points
    EXPECT_EQ(AOC_2022::rps_your_score("Z"), 3);
}

TEST(Day2_2022_Test, CalculatePlayResult) {
    // Rock = Rock - Draw (3 Points)
    EXPECT_EQ(AOC_2022::rps_play_result("A", "X"), 3);
    // Paper < Scissors - Win (6 Points)
    EXPECT_EQ(AOC_2022::rps_play_result("B", "Z"), 6);
    // Scissors > Paper - Loss (0 Points)
    EXPECT_EQ(AOC_2022::rps_play_result("C", "Y"), 0);
}

TEST(Day2_2022_Test, CalculatePlayScore) {
    EXPECT_EQ(AOC_2022::calculate_play_score("A Y"), 8);
    EXPECT_EQ(AOC_2022::calculate_play_score("B X"), 1);
    EXPECT_EQ(AOC_2022::calculate_play_score("C Z"), 6);
}

TEST(Day2_2022_Test, CalculateTotalScore) {
    std::vector<std::string> input = {
            "A Y",
            "B X",
            "C Z",
    };

    EXPECT_EQ(AOC_2022::calculate_total_score(input), 15);
}

TEST(Day2_2022_Test, FindRequiredPlay) {
    EXPECT_EQ(AOC_2022::find_required_play("A Y"), "A X");
    EXPECT_EQ(AOC_2022::find_required_play("B X"), "B X");
    EXPECT_EQ(AOC_2022::find_required_play("C Z"), "C X");
}

TEST(Day2_2022_Test, FindRequiredPlays) {
    std::vector<std::string> input = {
            "A Y",
            "B X",
            "C Z",
    };

    std::vector<std::string> expected = {
            "A X",
            "B X",
            "C X",
    };
    EXPECT_EQ(AOC_2022::find_plays(input), expected);
}