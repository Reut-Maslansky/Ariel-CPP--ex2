#include <string>
#include <vector>
#include "Direction.hpp"

// namespace ariel {
//     class Board {
//         char** chars;
//         uint rows;
//         uint cols;
//     public:
//         Board() {
//          //   chars= new char[this->rows][cols];
//          }
//         ~Board() {
//             //delete [] chars;
//             }
//         void post(int row, int column, Direction direction, std::string message);
//         std::string read(int row, int column, Direction direction, int length);
//         void show();
//     };
// }

namespace ariel
{
    class Board
    {
        std::vector<std::vector<char>> b;
        uint rows;
        uint cols;

    public:
        Board();
        // ~Board();
        void post(unsigned int row, unsigned int column, Direction direction, std::string message);
        std::string read(unsigned int row, unsigned int column, Direction direction, unsigned int length);
        void show();
    };
}