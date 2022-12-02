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
    static Solution day2_solve();
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

    // ----------------------------------------- DAY 2 -----------------------------------------
    /**
     * Calculate the total score according to the strategy guide
     *
     * @param guide The strategy guide provided by the
     * @return The total score
     */
    static int calculate_total_score(const std::vector<std::string>  &guide);

    /**
     * Calculate the score resulting from a play. The play must be in the format
     *      A Y
     * @param play The play
     * @return The play score
     */
    static int calculate_play_score(const std::string &play);

    /**
     * Determine the outcome of a rock paper scissors play and return the score from
     * that outcome
     *
     * @param opp The opponent play, ex: "B"
     * @param you Your play, ex: "Z"
     * @return 0 for loss, 3 for draw, 6 for win
     */
    static int rps_play_result(const std::string &opp, const std::string &you);

    /**
     * Calculate how many points you score just from choosing rock, paper or scissors
     *
     * @param you Your play
     * @return 1 for Rock, 2 for Paper, 3 for Scissors
     */
    static int rps_your_score(const std::string &you);

    /**
     * Find all plays you need to make to achieve the results stated in the guide
     *
     * @param guide The strategy guide given by the elf
     * @return The list of plays that will be made by the opponent and you
     */
    static std::vector<std::string> find_plays(const std::vector<std::string> &guide);

    /**
     * Find required play you need to make to achieve the desired result
     *      If "A Y", you need to choose Rock ("X") to achieve the result of Draw ("Y")
     *  We return the plays that match the format of part 1 ("A|B|C X|Y|X") in order to allow us to
     *  re-use the functions already made
     *
     * @param result The play result that needs to occur
     * @return The play that needs to be made
     */
    static std::string find_required_play(const std::string &result);
};

#endif //ADVENT_OF_CODE_AOC_2022_H
