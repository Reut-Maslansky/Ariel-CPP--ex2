#include "Board.hpp"
// #include <vector>
#include <string>
// #include <iostream>
using namespace std;

namespace ariel
{
    Board::Board()
    {
        rows = 0;
        cols = 0;
    }
    Board::~Board()
    {
    }
    void Board::post(unsigned int row, unsigned int column, Direction direction, string message)
    {
        //resize cols
        if (column + message.length() > cols)
        {
            for (unsigned int i = 0; i < rows; i++)
            {
                for (int j = 0; j < (column + message.length() - cols + 1); j++)
                {
                    b.at(i).push_back('_');
                }
            }
            cols = column + message.length();
        }

        //resize rows
        if (row + message.length() > rows)
        {
            for (int i = 0; i < (row + message.length() - rows + 1); i++)
            {
                vector<char> n;
                for (int j = 0; j < cols; j++)
                {
                    n.push_back('_');
                }
                b.push_back(n);
            }
            rows = row + message.length();
        }
        for (unsigned int i = 0; i < message.length(); i++)
        {
            if (direction == Direction::Horizontal)
                b.at(row).at(column + i) = message.at(i);
            else
                b.at(row + i).at(column) = message.at(i);
        }
    }
    std::string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int length)
    {
        if (length == 0)
            // throw string("message length can't be zero");
            return "";

        if (row > rows || column > cols)
            throw string("There is no such place on the board");

        string msg;
        for (unsigned int i = 0; i < length; i++)
        {
            if (direction == Direction::Horizontal)
                msg += b.at(row).at(column + i);
            else
                msg += b.at(row + i).at(column);
        }
        return msg;
    }
    void Board::show()
    {
    }
}
