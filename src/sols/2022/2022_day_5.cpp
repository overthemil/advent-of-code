//
// Advent of Code - 2022
// https://adventofcode.com/2022
// Created by Pedro Alves
//

#include "aoc_2022.h"
#include "aoc_utils.h"

#include <iostream>
#include <utility>

Solution AOC_2022::day5_solve() {
    std::vector<std::string> input = read_file("input/2022/Day_5.txt");
    std::cout << "Day 5 - 2022:" << std::endl;
    Solution solution = {"Not implemented", "Not implemented", 0};

    auto stacks = day_5_get_stacks(input);
    auto commands_string = day_5_get_commands_strings(input);
    auto commands = day_5_get_commands(commands_string);
    auto new_stacks = day_5_run_commands(commands, stacks);
    solution.part1 = day_5_get_top_crates(new_stacks);

    auto new_stacks_9001 = day_5_run_commands_9001(commands, stacks);
    solution.part2 = day_5_get_top_crates(new_stacks_9001);

    return solution;
}

int AOC_2022::day_5_get_max_stack_size(const std::vector<std::string> &commands) {
    int stack_size = 0;

    for (int i = 0; i < commands.size(); i++) {
        if (commands[i].empty()) {
            stack_size = i;
            break;
        }
    }

    return stack_size - 1;
}


int AOC_2022::day_5_get_num_stacks(const std::vector<std::string> &commands) {
    // Must have a + 1 since the last stack does not have a space in it in the input unlike the other stacks
    return (int) (commands[0].length() + 1) / 4;
}


std::vector<std::stack<char>> AOC_2022::day_5_get_stacks(const std::vector<std::string> &commands) {
    std::vector<std::stack<char>> stacks;

    int max_stack_size = day_5_get_max_stack_size(commands);
    int num_stacks = day_5_get_num_stacks(commands);

    for (int i = 0; i < num_stacks; i++) {
        // The input is in the format:
        // [A] [B] [C] [D]
        //  ^   ^   ^   ^
        //  |   |   |   |
        //  1   5   9   13
        int index = i * 4 + 1;

        std::stack<char> stack;

        // Since we're using a Stack container, we need to iterate through the input in reverse order so that
        // the bottom crates actually end up in the bottom
        for (int j = max_stack_size - 1; j >= 0; j--) {
            char ch = commands[j].at(index);
            if (ch != ' ') {
                stack.push(ch);
            }
        }
        stacks.push_back(stack);
    }

    return stacks;
}

std::vector<std::string> AOC_2022::day_5_get_commands_strings(const std::vector<std::string> &input) {
    std::vector<std::string> commands;

    for (int i = day_5_get_max_stack_size(input) + 2; i < input.size(); i++) {
        commands.push_back(input[i]);
    }

    return commands;
}

std::vector<CraneCommand> AOC_2022::day_5_get_commands(const std::vector<std::string> &commands) {
    std::vector<CraneCommand> comm;

    for (const auto &command: commands) {
        auto str = split(command, " ");
        CraneCommand craneCommand = {std::stoi(str[3]), std::stoi(str[5]), std::stoi(str[1])};
        comm.push_back(craneCommand);
    }

    return comm;
}

std::vector<std::stack<char>>
AOC_2022::day_5_run_commands(const std::vector<CraneCommand> &commands, std::vector<std::stack<char>> initStack) {
    std::vector<std::stack<char>> stacks = std::move(initStack);

    for (const auto &command: commands) {
        for (int i = 0; i < command.count; i++) {
            char crate = stacks.at(command.start - 1).top();
            stacks.at(command.start - 1).pop();
            stacks.at(command.end - 1).push(crate);
        }
    }

    return stacks;
}

std::string AOC_2022::day_5_get_top_crates(const std::vector<std::stack<char>> &stack) {
    std::string crates;

    for (const auto &s: stack) {
        crates += s.top();
    }

    return crates;
}

std::vector<std::stack<char>>
AOC_2022::day_5_run_commands_9001(const std::vector<CraneCommand> &commands, std::vector<std::stack<char>> initStack) {
    std::vector<std::stack<char>> stacks = std::move(initStack);

    for (const auto &command: commands) {
        std::stack<char> tmp_stack;
        for (int i = 0; i < command.count; i++) {
            char crate = stacks.at(command.start - 1).top();
            stacks.at(command.start - 1).pop();
            tmp_stack.push(crate);
        }

        while(!tmp_stack.empty()) {
           char crate = tmp_stack.top();
           tmp_stack.pop();
           stacks.at(command.end - 1).push(crate);
       }
    }

    return stacks;
}
