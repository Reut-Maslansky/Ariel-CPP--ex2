/**
 * Demo program for message-board exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-03
 */

#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
	ariel::Board board;
	// board.post(/*row=*/100, /*column=*/200, Direction::Horizontal, "abcd");
	// cout << board.read(/*row=*/99, /*column=*/201, Direction::Vertical, /*length=*/3) << endl;
	// 	// prints "_b_" (starts at row 99 which is empty; then at row 100 there is "b"; then row 101 is empty again).
	// board.post(/*row=*/99, /*column=*/202, Direction::Vertical, "xyz");
	// cout << board.read(/*row=*/100, /*column=*/200, Direction::Horizontal, /*length=*/6) << endl;
	// 	// prints "abyd__" (First letters are ab; then y from the "xyz"; then d; then two empty cells).

	// board.show(); // shows the board in a reasonable way. For example:
	// 	//    98:  _________
	// 	//    99:  ____x____
	// 	//    100: __abyd___
	// 	//    101: ____z____
	// 	//    102: _________

	ariel::Board b;
	b.post(0, 0, Direction::Horizontal, "        \\\\|||||//        ");
	b.post(1, 0, Direction::Horizontal, "        ( O   O )        ");
	b.post(2, 0, Direction::Horizontal, "|--ooO-----(_)----------|");
	b.post(3, 0, Direction::Horizontal, "|                       |");
	b.post(4, 0, Direction::Horizontal, "|                       |");
	b.post(5, 0, Direction::Horizontal, "|     Message Board     |");
	b.post(6, 0, Direction::Horizontal, "|                       |");
	b.post(7, 0, Direction::Horizontal, "|                       |");
	b.post(8, 0, Direction::Horizontal, "|------------------Ooo--|");
	b.post(9, 0, Direction::Horizontal, "        |__|  |__|       ");
	b.post(10, 0, Direction::Horizontal, "         ||    ||        ");
	b.post(11, 0, Direction::Horizontal, "        ooO    Ooo       ");
	b.show();

	board.show();
	cout << endl;
	board.post(0, 0, Direction::Horizontal, "Reut");
	board.show();
	cout << endl;
	board.post(0, 0, Direction::Vertical, "Reut");
	board.show();
	cout << endl;
	board.post(0, 3, Direction::Vertical, "Mas");
	board.show();
	cout << endl;
	board.post(5, 2, Direction::Horizontal, "Yakir");
	board.post(4, 6, Direction::Horizontal, "temp");
	board.post(1, 6, Direction::Vertical, "ariela");
	board.show();
}
