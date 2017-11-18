/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#include <iostream>

#include "game/sudoku.hpp"

int main() {
    auto v_puzzle = Sudoku::create_std();
    for(int i = 0; i < 9; i++) {
        for(const auto& j : v_puzzle[i]) {
            std::cout << j;
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    return 0;
}
