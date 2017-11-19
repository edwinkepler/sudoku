/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <vector>

/** @brief Time of the last operation. */
static float f_time = 0;

/** @brief Sudoku generating and solving algorithms. */
class Sudoku {
    public:
    /**
     * @brief Creates standard sudoku 9x9 board.
     * @return 2d vector of a valid standard sudoku board.
     */
    static std::vector<std::vector<short>> create_std();
    /**
     * @brief Get time of the last operation.
     * @return Time of the last operation.
     */
    static float time();
};

#endif // SUDOKU_HPP
