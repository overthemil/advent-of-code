//
// Created by pedro on 01/12/22.
//

#ifndef ADVENT_OF_CODE_AOC_2022_H
#define ADVENT_OF_CODE_AOC_2022_H

#include <map>
#include <functional>
#include <stack>

#include "aoc_types.h"
#include "files.h"

// ------------------------------------- DAY 5 Classes -------------------------------------
struct CraneCommand {
    // The stack to pick up the crate from
    int start;
    // The stack to place the crate on
    int end;
    // How many crates to move
    int count;

    // Used for testing
    friend bool operator==(const CraneCommand &l, const CraneCommand &r) {
        return std::tie(l.start, l.end, l.count)
               == std::tie(r.start, r.end, r.count);
    }
};

// ------------------------------------------ AOC  -----------------------------------------

class AOC_2022 {
    std::map<int, std::function<Solution()>> solutions;

    static Solution day1_solve();

    static Solution day2_solve();

    static Solution day3_solve();

    static Solution day4_solve();

    static Solution day5_solve();

    static Solution day6_solve();

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
    static std::vector<int> day_1_aggregate_calories(const std::vector<std::string> &meals);

    /**
     * Gets a sum of the calorie meal total for the 3 elves with the most calories brought
     *
     * @param calories A list of each elf's calories brought
     * @return The total calorie total brought by the elves with the top 3 caloric meals
     */
    static int day_1_calculate_top_three(std::vector<int> &calories);

    // ----------------------------------------- DAY 2 -----------------------------------------

    /**
     * Calculate the total score according to the strategy guide
     *
     * @param guide The strategy guide provided by the
     * @return The total score
     */
    static int day_2_calculate_total_score(const std::vector<std::string> &guide);

    /**
     * Calculate the score resulting from a play. The play must be in the format
     *      A Y
     * @param play The play
     * @return The play score
     */
    static int day_2_calculate_play_score(const std::string &play);

    /**
     * Determine the outcome of a rock paper scissors play and return the score from
     * that outcome
     *
     * @param opp The opponent play, ex: "B"
     * @param you Your play, ex: "Z"
     * @return 0 for loss, 3 for draw, 6 for win
     */
    static int day_2_rps_play_result(const std::string &opp, const std::string &you);

    /**
     * Calculate how many points you score just from choosing rock, paper or scissors
     *
     * @param you Your play
     * @return 1 for Rock, 2 for Paper, 3 for Scissors
     */
    static int day_2_rps_your_score(const std::string &you);

    /**
     * Find all plays you need to make to achieve the results stated in the guide
     *
     * @param guide The strategy guide given by the elf
     * @return The list of plays that will be made by the opponent and you
     */
    static std::vector<std::string> day_2_find_plays(const std::vector<std::string> &guide);

    /**
     * Find required play you need to make to achieve the desired result
     *      If "A Y", you need to choose Rock ("X") to achieve the result of Draw ("Y")
     *  We return the plays that match the format of part 1 ("A|B|C X|Y|X") in order to allow us to
     *  re-use the functions already made
     *
     * @param result The play result that needs to occur
     * @return The play that needs to be made
     */
    static std::string day_2_find_required_play(const std::string &result);

    // ----------------------------------------- DAY 3 -----------------------------------------
    /**
     * When provided with a string containing all items that a backpack contains, it will return
     * two strings with the items each compartment in the bag has
     *
     * @return A vector with two strings, each showing the items that are in each container
     */
    static std::vector<std::string> day_3_find_compartment_items(const std::string &backpack);

    /**
     * Find the common item that is present in both compartments
     *
     * @param compartments A vector of strings with items in each compartment
     * @return A vector containing all items that are present in both compartments
     */
    static std::vector<char> day_3_find_common_item(const std::vector<std::string> &compartments);

    /**
     * Find the priority for the given item,
     *      a through z have values 1 through 26
     *      A through Z have values 27 through 52
     *
     * @param item The item to check
     * @return The priority of the item
     */
    static int day_3_find_item_priority(char item);

    /**
     * Find the common items in each compartment in a list of backpacks and sum their priorities
     *
     * @param backpacks All backpacks carried by the elves
     * @return A total sum of all priorities of the common items in the backpacks
     */
    static int day_3_find_total_priority_of_rucksacks(const std::vector<std::string> &backpacks);

    /**
     * Find the badge of each group and sum all of their priorities
     *
     * @param backpacks All backpacks carried by the elves
     * @return A sum of all priorities of each badge
     */
    static int day_3_find_total_priority_of_badges(const std::vector<std::string> &backpacks);

    /**
     * Find the badge representing the groups. This is the item that is common to all three backpacks that
     * belong to the groups
     *
     * @param groups The three backpacks belonging to the groups
     * @return The item that makes the badge of the groups
     */
    static char day_3_find_group_badge(const std::vector<std::string> &groups);

    // ----------------------------------------- DAY 4 -----------------------------------------
    /**
     * Takes the assignments of a pair of elves and returns each group's assignments in separate containers
     *
     * @param assignment The assignments of the pair, ex: "6-8,5-10"
     * @return The assignments of each pair
     */
    static std::pair<std::string, std::string> day_4_split_assignments(const std::string &assignment);

    /**
     * Gets all numbers within the associated range provided by the assignment
     *
     * @param assignment The assignment range. Ex: 3-10
     * @return A vector containing all of the numbers in the range
     */
    static std::vector<int> day_4_get_range(const std::string &assignment);

    /**
     * Count all assignments that are fully in range of another
     *
     * @param assignments All of the assignments of the elves
     * @return How many are fully contained by the other
     */
    static int day_4_fully_contained_ranges(const std::vector<std::string> &assignments);

    /**
     * Check how many assignment pairs have overlapping ranges
     *
     * @param assignments All of the assignments of the elves
     * @return How many assignment pairs overlap
     */
    static int day_4_intersecting_ranges(const std::vector<std::string> &assignments);

    // ----------------------------------------- DAY 5 -----------------------------------------

    /**
     * Find the biggest sized stack of the currently stacked boxes
     *
     * @param commands The input with the stack and commands
     * @return The maximum size of the stacks
     */
    static int day_5_get_max_stack_size(const std::vector<std::string> &commands);

    /**
     * Find how many stacks there are present
     *
     * @param commands The input with the stack and commands
     * @return How many stacks are present
     */
    static int day_5_get_num_stacks(const std::vector<std::string> &commands);

    /**
     * Parse the input into a STL container that can be used to simulate the commands
     *
     * @param commands THe input with the stack and commands
     * @return The stack of crates
     */
    static std::vector<std::stack<char>> day_5_get_stacks(const std::vector<std::string> &commands);


    /**
     * Separate the stack and command information
     *
     * @param input The input with the stack and commands
     * @return Command information from the input as an array of strings
     */
    static std::vector<std::string> day_5_get_commands_strings(const std::vector<std::string> &input);

    /**
     * Parse commands strings in order to create CrateCommand objects
     *
     * @param commands Input with crane commands strings
     * @return An array with CraneCommands
     */
    static std::vector<CraneCommand> day_5_get_commands(const std::vector<std::string> &commands);

    /**
     * Run the commands to move the crates in the stacks
     *
     * @param commands Input with crane commands
     * @param initStack The initial state of the stack
     * @return The resulting stack
     */
    static std::vector<std::stack<char>>
    day_5_run_commands(const std::vector<CraneCommand> &commands, std::vector<std::stack<char>> initStack);

    /**
     * Get the top crate from each stack
     *
     * @param stack The stacks of crates
     * @return The top crates as a string. Ex: "CMZ"
     */
    static std::string day_5_get_top_crates(const std::vector<std::stack<char>> &stack);

    /**
     * Run the commands to move the crates in the stacks. It uses the functionality of the CrateMover 9001
     *
     * @param commands Input with crane commands
     * @param initStack The inital state of the stack
     * @return The resulting stack
     */
    static std::vector<std::stack<char>>
    day_5_run_commands_9001(const std::vector<CraneCommand> &commands, std::vector<std::stack<char>> initStack);

    // ----------------------------------------- DAY 6 -----------------------------------------

   /**
    * The start of packet marker is indicated in the input by a sequence of seq_size characters that are all different.
    *
    * @param input The message datastream
    * @param seq_size How many characters long is the sequence
    * @return The marker position after the sequence
    */
    static int day_6_find_marker_pos(const std::string &input, int seq_size);
};

#endif //ADVENT_OF_CODE_AOC_2022_H
