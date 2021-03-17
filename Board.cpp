#include "Board.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

namespace ariel
{
    Board::Board()
    {
        rows = 0;
        cols = 0;
    }
    // Board::~Board()
    // {
    // }
    void Board::post(unsigned int row, unsigned int column, Direction direction, string message)
    {
        // if(rows==0&&cols==0&&message.length()>0){
        //     b.push_back(vector<char> (1,'_'));
        // }
        
        //resize cols
        if (column + message.length() > cols ) //&& direction == Direction::Horizontal
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
        if (row + message.length() > rows ) //&& direction == Direction::Vertical
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
    string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int length)
    {
        if (length == 0)
            return "";

        string msg;
        unsigned int current_len = length;
        unsigned int space_len = 0;
        if (direction == Direction::Horizontal)
        {
            if (row > rows)
            {
                for (int i = 0; i < length; i++)
                    msg += "_";
                return msg;
            }

            if (row + length > rows)
            {
                space_len = row + length - rows;
                current_len = length - space_len;
            }
        }
        else
        {
            if (column > cols)
            {
                for (int i = 0; i < length; i++)
                    msg += "_";
                return msg;
            }
            if (column + length > cols)
            {
                space_len = column + length - cols;
                current_len = length - space_len;
            }
        }

        for (unsigned int i = 0; i < current_len; i++)
        {
            if (direction == Direction::Horizontal)
                msg += b.at(row).at(column + i);
            else
                msg += b.at(row + i).at(column);
        }

        for (int i = 0; i < space_len; i++)
            msg += "_";

        return msg;
    }

    
    void Board::show()
    {
        for (unsigned long i = 0; i < b.size(); i++)
        {
            cout << i<<":\t";
            for (unsigned long j = 0; j < b.at(i).size(); j++)
            {
                cout << b.at(i).at(j);
            }
            cout << endl;
        }
    }
}