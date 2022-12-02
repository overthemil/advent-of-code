#include "aoc.h"
#include "aoc_types.h"

#include <chrono>
#include <iostream>

Solution AOC::solve(int year, int day) {
    using namespace std::chrono;

    Solution solution;

    auto start = high_resolution_clock::now();

    switch(year) {
        case 2022:
            solution = aoc_2022.solve(day);
            break;
        default:
            std::cout << "Year not recognised - " << year << std::endl;
            break;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    solution.time_taken = duration.count();

    return solution;
}