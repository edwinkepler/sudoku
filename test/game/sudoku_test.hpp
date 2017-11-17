/*
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef SUDOKU_TEST_HPP
#define SUDOKU_TEST_HPP

#include "game/sudoku.hpp"

#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(test)
{
    BOOST_REQUIRE_EQUAL(1, 1);
}

#endif // SUDOKU_TEST_HPP
