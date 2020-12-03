#pragma once
#include "Piece.h"

namespace TheRoyalFamily
{
    class Rook :
        public Piece
    {
    public:
        Rook(char file, int rank, char colour, char code = 'R');
        bool move(std::string target_pos);
    };
}
