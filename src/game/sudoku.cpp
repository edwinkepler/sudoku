/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#include <random>
#include "sudoku.hpp"

std::vector<short> Sudoku::create_std() {
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> nine(1, 9);

    std::vector<short> v_line;
    bool f_valid_line = false;
    while(!f_valid_line) {
        // randomize number
        short tmp = nine(eng);
        // put it on back of a vector
        v_line.push_back(tmp);
        if(v_line.size() > 1) {
            // check every element except last one
            for(int i = 0; i < v_line.size() - 1; i++) {
                // if any element equals to the last one - pop it and break the loop
                if(v_line[i] == v_line[v_line.size() - 1]) {
                    v_line.pop_back();
                    break;
                }
            }
            if(v_line.size() == 9) {
                f_valid_line = true;
            }
        }
    }
    return v_line;
}
