/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#include <random>
#include <chrono>
#include "sudoku.hpp"

std::vector<std::vector<short>> Sudoku::create_std() {
    // start timer
    auto start_time = std::chrono::high_resolution_clock::now();
    // init randomize engine
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> nine(1, 9);

    std::vector<std::vector<short>> v_sudoku;
    bool b_valid_sudoku = false;
    while(!b_valid_sudoku) {
        // create std sudoku line
        std::vector<short> v_lines;
        bool b_valid_line = false;
        while(!b_valid_line) {
            // randomize number
            short tmp = nine(eng);
            // put it on back of a vector
            v_lines.push_back(tmp);
            if(v_lines.size() > 1) {
                // check every element except last one
                for(int i = 0; i < v_lines.size() - 1; i++) {
                    // if any element equals to the last one - pop it and break the loop
                    if(v_lines[i] == v_lines[v_lines.size() - 1]) {
                        v_lines.pop_back();
                        break;
                    }
                }
                // if there is 9 valid elements break the while loop
                if(v_lines.size() == 9) {
                    v_sudoku.push_back(v_lines);
                    b_valid_line = true;
                }
            }
        }
        if(v_sudoku.size() > 1) {
            for(int i = 0; i < 9; i++) {
                // check every element except last one
                for(int j = 0; j < v_sudoku.size() - 1; j++) {
                    // if any element equals to the last one - pop it and break the loop
                    if(v_sudoku[j][i] == v_sudoku[v_sudoku.size() - 1][i]) {
                        v_sudoku.pop_back();
                        break;
                    }
                }
            }
        }
        // if there is 8 valid lines you can make last line automaticaly
        // by calculating sum of prev 8 lines
        if(v_sudoku.size() == 8) {
            std::vector<short> v_line;
            for(int i = 0; i < 9; i++) {
                short tmp = 0;
                for(int j = 0; j < 8; j++) {
                    tmp += v_sudoku[j][i];
                }
                v_line.push_back(45 - tmp);
            }
            v_sudoku.push_back(v_line);
            b_valid_sudoku = true;
        }
    }
    // stop timer
    auto current_time = std::chrono::high_resolution_clock::now();
    f_time = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count();
    return v_sudoku;
}

float Sudoku::time() {
    return f_time;
}
