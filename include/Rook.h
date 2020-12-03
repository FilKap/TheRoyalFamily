#pragma once
#include "Piece.h"

namespace TheRoyalFamily
{
    class Rook :
        public Piece
    {
    private:
        bool checkSquaresAreFree(std::string pos) const;     // wheter squares are free until pos
    public:
        Rook(char file, int rank, char colour, char code = 'R');
        bool move(std::string target_pos);
    };
}
