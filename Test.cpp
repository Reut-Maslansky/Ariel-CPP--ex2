#include "doctest.h"
#include "Board.hpp"
#include <string>
using namespace ariel;
using namespace std;

TEST_CASE("test post")
{
    Board board;
    CHECK_NOTHROW(board.post(0, 0, Direction::Horizontal, "Reut"));
    CHECK_NOTHROW(board.post(0, 0, Direction::Vertical, "Reut"));
}
TEST_CASE("test Horizontal")
{
    Board board;
    CHECK_NOTHROW(board.post(0, 0, Direction::Horizontal, "Reut"));
    CHECK(board.read(0, 0, Direction::Horizontal, 4) == string("Reut"));

}
TEST_CASE("test Vertical")
{
    Board board;
    CHECK_NOTHROW(board.post(0, 0, Direction::Vertical, "Reut"));
}
TEST_CASE("test read")
{
    Board board;
    CHECK_THROWS(board.read(0, 0, Direction::Horizontal, 4));
}
TEST_CASE("test read- length 0")
{
    Board board;
    CHECK(board.read(0, 0, Direction::Horizontal, 0)=="");
    CHECK(board.read(0, 0, Direction::Vertical, 0)=="");
}
TEST_CASE("corners")
{
    Board board;
}