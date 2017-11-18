/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#include <iostream>

#include "game/sudoku.hpp"

void print_sudoku_std(std::vector<std::vector<short>> _puzzle) {
    std::cout << "  ABC DEF GHI" << std::endl;
    for(int i = 0; i < 9; i++) {
        if(i == 3 || i == 6) {
            std::cout << "  ";
            for(int k = 0; k < 11; k++) {
                if(k == 3 || k == 7) {
                    std::cout << "|";
                } else {
                    std::cout << "-";
                }
            }
            std::cout << std::endl;
        }
        std::cout << i + 1 << " ";
        for(int j = 0; j < 9; j++) {
            if(j == 3 || j == 6) {
                std::cout << "|";
            }
            std::cout << _puzzle[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    auto v_puzzle = Sudoku::create_std();
    print_sudoku_std(v_puzzle);
    return 0;
}
