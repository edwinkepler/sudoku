/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#include <iostream>

#include "game/sudoku.hpp"

int main() {
    auto v_puzzle = Sudoku::create_std();
    for(const auto& i : v_puzzle) {
        std::cout << i;
    }
    std::cout << std::endl;
    return 0;
}
