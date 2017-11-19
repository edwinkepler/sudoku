/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <vector>

/** @brief Sudoku generating and solving algorithms. */
class Sudoku {
    public:
    /**
     * @brief Creates standard sudoku 9x9 board.
     * @return 2d vector of a valid standard sudoku board.
     */
    static std::vector<std::vector<short>> create_std();
};

#endif // SUDOKU_HPP
