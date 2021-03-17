#include "doctest.h"
#include "Board.hpp"
#include <string>
using namespace ariel;
using namespace std;

Board board;

TEST_CASE("test read before post")
{
    CHECK(board.read(0, 0, Direction::Horizontal, 1) == string("_"));
    CHECK(board.read(0, 0, Direction::Horizontal, 2) == string("__"));
    CHECK(board.read(0, 0, Direction::Vertical, 1) == string("_"));
    CHECK(board.read(0, 0, Direction::Vertical, 2) == string("__"));
    CHECK(board.read(34, 100, Direction::Vertical, 5) == string("_____"));
    CHECK(board.read(23, 54, Direction::Horizontal, 4) == string("____"));
}

TEST_CASE("test post")
{
    
    CHECK_NOTHROW(board.post(0, 0, Direction::Horizontal, "Reut"));
    CHECK_NOTHROW(board.post(0, 0, Direction::Vertical, "Reut"));
    CHECK_NOTHROW(board.post(0, 3, Direction::Vertical, "Mas"));
    CHECK_NOTHROW(board.post(5, 2, Direction::Horizontal, "Yakir"));
    CHECK_NOTHROW(board.post(4, 6, Direction::Horizontal, "temp"));
    CHECK_NOTHROW(board.post(1, 6, Direction::Vertical, "ariela"));
}

TEST_CASE("test read corner")
{
    CHECK(board.read(6, 8, Direction::Horizontal, 5) == string("_____"));
    CHECK(board.read(5, 4, Direction::Vertical, 3) == string("k__"));
    CHECK(board.read(0, 2, Direction::Vertical, 10) == string("u____Y____"));
    CHECK(board.read(6, 9, Direction::Vertical, 3) == string("___"));
}

TEST_CASE("uppercase or lowercase letters")
{
}


TEST_CASE("test Horizontal")
{
}
TEST_CASE("test Vertical")
{
}

TEST_CASE("test read- length 0")
{
    CHECK(board.read(0, 0, Direction::Horizontal, 0) == "");
    CHECK(board.read(0, 0, Direction::Vertical, 0) == "");
}
TEST_CASE("specil chars")
{
}