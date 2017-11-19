/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#include <random>
#include "sudoku.hpp"

std::vector<std::vector<short>> Sudoku::create_std() {
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> nine(1, 9);

    std::vector<std::vector<short>> v_sudoku;
    bool b_valid_sudoku = false;
    while(!b_valid_sudoku) {
        // create std sudoku line
        std::vector<short> v_line;
        bool b_valid_line = false;
        while(!b_valid_line) {
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
                // if there is 9 valid elements break the while loop
                if(v_line.size() == 9) {
                    v_sudoku.push_back(v_line);
                    b_valid_line = true;
                }
            }
        }
        if(v_sudoku.size() > 1) {
            for(int i = 0; i < 9; i++) {
                for(int j = 0; j < v_sudoku.size() - 1; j++) {
                    if(v_sudoku[j][i] == v_sudoku[v_sudoku.size() - 1][i]) {
                        v_sudoku.pop_back();
                        break;
                    }
                }
            }
        }
        // if there is 9 valid lines then break the loop
        if(v_sudoku.size() == 9) {
            b_valid_sudoku = true;
        }
    }
    return v_sudoku;
}
