#include <gtest/gtest.h>
#include "sols/2022/aoc_2022.h"

TEST(Day5_2022_Test, GetMaxStackSize) {
    std::vector<std::string> input = {
            "    [D]    ",
            "[N] [C]    ",
            "[Z] [M] [P]",
            " 1   2   3 ",
            "",
            "move 1 from 2 to 1",
            "move 3 from 1 to 3",
            "move 2 from 2 to 1",
            "move 1 from 1 to 2"
    };

    EXPECT_EQ(AOC_2022::day_5_get_max_stack_size(input), 3);
}

TEST(Day5_2022_Test, GetNumStacks) {
    std::vector<std::string> input = {
            "    [D]    ",
            "[N] [C]    ",
            "[Z] [M] [P]",
            " 1   2   3 ",
            "",
            "move 1 from 2 to 1",
            "move 3 from 1 to 3",
            "move 2 from 2 to 1",
            "move 1 from 1 to 2"
    };

    EXPECT_EQ(AOC_2022::day_5_get_num_stacks(input), 3);
}

TEST(Day5_2022_Test, GetStacks) {
    std::vector<std::string> input = {
            "    [D]    ",
            "[N] [C]    ",
            "[Z] [M] [P]",
            " 1   2   3 ",
            "",
            "move 1 from 2 to 1",
            "move 3 from 1 to 3",
            "move 2 from 2 to 1",
            "move 1 from 1 to 2"
    };

    std::vector<std::stack<char>> expected;
    std::stack<char> stack_1;
    stack_1.push('Z');
    stack_1.push('N');
    std::stack<char> stack_2;
    stack_2.push('M');
    stack_2.push('C');
    stack_2.push('D');
    std::stack<char> stack_3;
    stack_3.push('P');
    expected.push_back(stack_1);
    expected.push_back(stack_2);
    expected.push_back(stack_3);

    EXPECT_EQ(AOC_2022::day_5_get_stacks(input), expected);
}

TEST(Day5_2022_Test, GetCommandStrings) {
    std::vector<std::string> input = {
            "    [D]    ",
            "[N] [C]    ",
            "[Z] [M] [P]",
            " 1   2   3 ",
            "",
            "move 1 from 2 to 1",
            "move 3 from 1 to 3",
            "move 2 from 2 to 1",
            "move 1 from 1 to 2"
    };

    std::vector<std::string> expected = {
            "move 1 from 2 to 1",
            "move 3 from 1 to 3",
            "move 2 from 2 to 1",
            "move 1 from 1 to 2"
    };

    EXPECT_EQ(AOC_2022::day_5_get_commands_strings(input), expected);
}

TEST(Day5_2022_Test, GetCommands) {
    std::vector<std::string> input = {
            "move 1 from 2 to 1",
            "move 3 from 1 to 3",
            "move 2 from 2 to 1",
            "move 1 from 1 to 2"
    };

    std::vector<CraneCommand> expected = {
            {2, 1, 1},
            {1, 3, 3},
            {2,1,2},
            {1,2,1}
    };

    EXPECT_EQ(AOC_2022::day_5_get_commands(input), expected);
}

TEST(Day5_2022_Test, RunCommands) {
    std::vector<CraneCommand> input_commands = {
            {2, 1, 1},
            {1, 3, 3},
            {2,1,2},
            {1,2,1}
    };
    std::vector<std::stack<char>> input_stack;
    std::stack<char> stack_1;
    stack_1.push('Z');
    stack_1.push('N');
    std::stack<char> stack_2;
    stack_2.push('M');
    stack_2.push('C');
    stack_2.push('D');
    std::stack<char> stack_3;
    stack_3.push('P');
    input_stack.push_back(stack_1);
    input_stack.push_back(stack_2);
    input_stack.push_back(stack_3);

    std::vector<std::stack<char>> expected;
    std::stack<char> e_stack_1;
    e_stack_1.push('C');
    std::stack<char> e_stack_2;
    e_stack_2.push('M');
    std::stack<char> e_stack_3;
    e_stack_3.push('P');
    e_stack_3.push('D');
    e_stack_3.push('N');
    e_stack_3.push('Z');
    expected.push_back(e_stack_1);
    expected.push_back(e_stack_2);
    expected.push_back(e_stack_3);
    EXPECT_EQ(AOC_2022::day_5_run_commands(input_commands, input_stack), expected);
}

TEST(Day5_2022_Test, GetTopCrates) {
    std::vector<std::stack<char>> input;
    std::stack<char> e_stack_1;
    e_stack_1.push('C');
    std::stack<char> e_stack_2;
    e_stack_2.push('M');
    std::stack<char> e_stack_3;
    e_stack_3.push('P');
    e_stack_3.push('D');
    e_stack_3.push('N');
    e_stack_3.push('Z');
    input.push_back(e_stack_1);
    input.push_back(e_stack_2);
    input.push_back(e_stack_3);

    EXPECT_EQ(AOC_2022::day_5_get_top_crates(input), "CMZ");
}

TEST(Day5_2022_Test, RunCommands9001) {
    std::vector<CraneCommand> input_commands = {
            {2, 1, 1},
            {1, 3, 3},
            {2,1,2},
            {1,2,1}
    };
    std::vector<std::stack<char>> input_stack;
    std::stack<char> stack_1;
    stack_1.push('Z');
    stack_1.push('N');
    std::stack<char> stack_2;
    stack_2.push('M');
    stack_2.push('C');
    stack_2.push('D');
    std::stack<char> stack_3;
    stack_3.push('P');
    input_stack.push_back(stack_1);
    input_stack.push_back(stack_2);
    input_stack.push_back(stack_3);

    std::vector<std::stack<char>> expected;
    std::stack<char> e_stack_1;
    e_stack_1.push('M');
    std::stack<char> e_stack_2;
    e_stack_2.push('C');
    std::stack<char> e_stack_3;
    e_stack_3.push('P');
    e_stack_3.push('Z');
    e_stack_3.push('N');
    e_stack_3.push('D');
    expected.push_back(e_stack_1);
    expected.push_back(e_stack_2);
    expected.push_back(e_stack_3);
    EXPECT_EQ(AOC_2022::day_5_run_commands_9001(input_commands, input_stack), expected);
}
