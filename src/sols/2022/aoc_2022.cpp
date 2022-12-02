//
// Advent of Code - 2022
// https://adventofcode.com/2022
// Created by Pedro Alves
//

#include "aoc_2022.h"
#include "aoc_utils.h"

#include <iostream>

AOC_2022::AOC_2022() {
    solutions = {
            {1, []() { return day1_solve(); }},
            {2, []() { return day2_solve(); }}
    };
}

Solution AOC_2022::solve(int day) {
    return solutions[day]();
}

// ----------------------------------------- DAY 1 -----------------------------------------
Solution AOC_2022::day1_solve() {
    std::vector<std::string> input = read_file("input/2022/Day_1.txt");
    std::cout << "Day 1 - 2022:" << std::endl;
    Solution solution = {"Not implemented", "Not implemented", 0};

    auto calories = aggregate_calories(input);
    int max_calories = *std::max_element(calories.begin(), calories.end());
    solution.part1 = std::to_string(max_calories);

    auto top_calories = calculate_top_three(calories);
    solution.part2 = std::to_string(top_calories);

    return solution;
}

std::vector<int> AOC_2022::aggregate_calories(const std::vector<std::string> &meals) {
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

int AOC_2022::calculate_top_three(std::vector<int> &calories) {
    std::sort(calories.begin(), calories.end(), std::greater<>());

    int top_calories = 0;
    if (calories.size() >= 3) {
        for (int i = 0; i < 3; i++) {
            top_calories += calories[i];
        }
    }

    return top_calories;
}

// ----------------------------------------- DAY 2 -----------------------------------------
Solution AOC_2022::day2_solve() {
    std::vector<std::string> input = read_file("input/2022/Day_2.txt");
    std::cout << "Day 2 - 2022:" << std::endl;
    Solution solution = {"Not implemented", "Not implemented", 0};

    solution.part1 = std::to_string(calculate_total_score(input));

    auto required_plays = find_plays(input);
    solution.part2 = std::to_string(calculate_total_score(required_plays));

    return solution;
}

int AOC_2022::calculate_total_score(const std::vector<std::string> &guide) {
    int score = 0;
    for (const auto &play: guide) {
        score += calculate_play_score(play);
    }
    return score;
}

int AOC_2022::calculate_play_score(const std::string &play) {
    int score = 0;

    auto str = split(play, " ");
    std::string opponent_play = str[0];
    std::string your_play = str[1];

    score += rps_play_result(opponent_play, your_play);
    score += rps_your_score(your_play);

    return score;
}

int AOC_2022::rps_play_result(const std::string &opp, const std::string &you) {
    // If the opponent plays rock
    if (opp == "A") {
        // If you played rock
        if (you == "X") {
            return 3;
            // If you played paper
        } else if (you == "Y") {
            return 6;
            // If you played scissors
        } else {
            return 0;
        }
        // If the opponent plays paper
    } else if (opp == "B") {
        // If you played rock
        if (you == "X") {
            return 0;
            // If you played paper
        } else if (you == "Y") {
            return 3;
            // If you played scissors
        } else {
            return 6;
        }
        // If the opponent plays scissors
    } else if (opp == "C") {
        // If you played rock
        if (you == "X") {
            return 6;
            // If you played paper
        } else if (you == "Y") {
            return 0;
            // If you played scissors
        } else {
            return 3;
        }
    }

    return 0;
}

int AOC_2022::rps_your_score(const std::string &you) {
    // If rock
    if (you == "X") {
        return 1;
        // If paper
    } else if (you == "Y") {
        return 2;
    }
        // If scissors
    else if (you == "Z") {
        return 3;
    }
    return 0;
}

std::vector<std::string> AOC_2022::find_plays(const std::vector<std::string> &guide) {
    std::vector<std::string> plays;

    for (const auto &play: guide) {
        plays.push_back(find_required_play(play));
    }

    return plays;
}

std::string AOC_2022::find_required_play(const std::string &result) {
    auto str = split(result, " ");
    std::string opponent_play = str[0];
    std::string result_req = str[1];

    std::string your_play;
    // If opponent plays rock
    if (opponent_play == "A") {
        // If we want to lose
        if (result_req == "X") {
            your_play = "Z";
        // If we want to draw
        } else if (result_req == "Y") {
            your_play = "X";
        // If we want to win
        } else if (result_req == "Z") {
            your_play = "Y";
        }
        // If opponent plays paper
    } else if (opponent_play == "B") {
        // If we want to lose
        if (result_req == "X") {
            your_play = "X";
        // If we want to draw
        } else if (result_req == "Y") {
            your_play = "Y";
        // If we want to win
        } else if (result_req == "Z") {
            your_play = "Z";
        }
        // If opponent plays scissors
    } else if (opponent_play == "C") {
        // If we want to lose
        if (result_req == "X") {
            your_play = "Y";
        // If we want to draw
        } else if (result_req == "Y") {
            your_play = "Z";
        // If we want to win
        } else if (result_req == "Z") {
            your_play = "X";
        }
    }

    return opponent_play + " " + your_play;
}




