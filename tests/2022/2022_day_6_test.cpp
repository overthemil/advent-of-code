#include <gtest/gtest.h>
#include "sols/2022/aoc_2022.h"

TEST(Day6_2022_Test, GetMarkerPosition) {
    EXPECT_EQ(AOC_2022::day_6_find_marker_pos("mjqjpqmgbljsphdztnvjfqwrcgsmlb",4), 7);
    EXPECT_EQ(AOC_2022::day_6_find_marker_pos("bvwbjplbgvbhsrlpgdmjqwftvncz",4), 5);
    EXPECT_EQ(AOC_2022::day_6_find_marker_pos("nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg",4), 10);
    EXPECT_EQ(AOC_2022::day_6_find_marker_pos("zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw",4), 11);
}

TEST(Day6_2022_Test, GetMessageMarkerPosition) {
    EXPECT_EQ(AOC_2022::day_6_find_marker_pos("mjqjpqmgbljsphdztnvjfqwrcgsmlb",14), 19);
    EXPECT_EQ(AOC_2022::day_6_find_marker_pos("bvwbjplbgvbhsrlpgdmjqwftvncz",14), 23);
    EXPECT_EQ(AOC_2022::day_6_find_marker_pos("nppdvjthqldpwncqszvftbrmjlhg",14), 23);
    EXPECT_EQ(AOC_2022::day_6_find_marker_pos("nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg",14), 29);
    EXPECT_EQ(AOC_2022::day_6_find_marker_pos("zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw",14), 26);
}
