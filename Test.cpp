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
    CHECK_NOTHROW(board.post(5, 6, Direction::Vertical, "W"));
}
TEST_CASE("test read- 1 post- no change")
{

    CHECK(board.read(0, 0, Direction::Vertical, 3) == string("Reu"));
    CHECK(board.read(0, 0, Direction::Vertical, 4) == string("Reut"));
    CHECK(board.read(0, 0, Direction::Vertical, 5) == string("Reut_"));

    CHECK(board.read(0, 3, Direction::Vertical, 2) == string("Ma"));
    CHECK(board.read(0, 3, Direction::Vertical, 3) == string("Mas"));
    CHECK(board.read(0, 3, Direction::Vertical, 4) == string("Mas_"));

    CHECK(board.read(2, 8, Direction::Vertical, 3) == string("__m"));
    CHECK(board.read(5, 2, Direction::Vertical, 10) == string("Y_________"));
}
TEST_CASE("after 2 posts at the same point")
{
    CHECK(board.read(0, 0, Direction::Horizontal, 3) == string("Reu"));
    CHECK(board.read(0, 0, Direction::Horizontal, 4) == string("ReuM"));
    CHECK(board.read(0, 0, Direction::Horizontal, 5) == string("ReuM_"));

    CHECK(board.read(4, 6, Direction::Horizontal, 3) == string("eem"));
    CHECK(board.read(4, 6, Direction::Horizontal, 4) == string("eemp"));
    CHECK(board.read(4, 5, Direction::Horizontal, 5) == string("_eemp"));
}

TEST_CASE("after 3 posts at the same point")
{

    CHECK(board.read(5, 3, Direction::Horizontal, 4) == string("akiW"));
    CHECK(board.read(5, 2, Direction::Horizontal, 5) == string("YakiW"));
    CHECK(board.read(5, 2, Direction::Horizontal, 6) == string("YakiW_"));

    CHECK(board.read(2, 6, Direction::Vertical, 5) == string("rieWa"));
    CHECK(board.read(1, 6, Direction::Vertical, 6) == string("arieWa"));
    CHECK(board.read(1, 6, Direction::Vertical, 7) == string("arieWa_"));
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
    CHECK_FALSE(board.read(0, 0, Direction::Horizontal, 4) == string("reum"));
    CHECK_FALSE(board.read(0, 0, Direction::Horizontal, 4) == string("rEUm"));
    CHECK_FALSE(board.read(0, 0, Direction::Horizontal, 4) == string("REUM"));
    CHECK(board.read(0, 0, Direction::Horizontal, 4) == string("ReuM"));
}

TEST_CASE("test Horizontal vs Vertical")
{
    CHECK_NOTHROW(board.post(5, 5, Direction::Horizontal, "hel"));
    CHECK(board.read(5, 5, Direction::Horizontal, 3) == "hel");
    CHECK_FALSE(board.read(5, 5, Direction::Vertical, 3) == "hel");
    CHECK_NOTHROW(board.post(5, 5, Direction::Vertical, "hel"));
    CHECK(board.read(5, 5, Direction::Vertical, 3) == "hel");
    CHECK(board.read(5, 5, Direction::Horizontal, 3) == "hel");
    CHECK_NOTHROW(board.post(3, 3, Direction::Vertical, "hi"));
    CHECK(board.read(3, 3, Direction::Vertical, 2) == "hi");
    CHECK_FALSE(board.read(3, 3, Direction::Horizontal, 2) == "hi");
}

TEST_CASE("test read- length 0")
{
    //0,0
    CHECK(board.read(0, 0, Direction::Horizontal, 0) == "");
    CHECK(board.read(0, 0, Direction::Vertical, 0) == "");
    //in the board
    CHECK(board.read(5, 4, Direction::Horizontal, 0) == "");
    CHECK(board.read(4, 5, Direction::Vertical, 0) == "");
    //corners of the board
    CHECK(board.read(6, 9, Direction::Horizontal, 0) == "");
    CHECK(board.read(6, 9, Direction::Vertical, 0) == "");
    //out of the board
    CHECK(board.read(10, 34, Direction::Horizontal, 0) == "");
    CHECK(board.read(34, 10, Direction::Vertical, 0) == "");
}

TEST_CASE("specil chars")
{
    CHECK_NOTHROW(board.post(5, 5, Direction::Horizontal, "?"));
    CHECK_NOTHROW(board.post(3, 4, Direction::Horizontal, "_"));
    CHECK_NOTHROW(board.post(1, 2, Direction::Horizontal, " "));
    CHECK_NOTHROW(board.post(6, 3, Direction::Horizontal, "*"));
    CHECK(board.read(5, 5, Direction::Vertical, 1) == "?");
    CHECK(board.read(3, 4, Direction::Vertical, 1) == "_");
    CHECK(board.read(1, 2, Direction::Vertical, 1) == " ");
    CHECK(board.read(6, 3, Direction::Vertical, 1) == "*");
}