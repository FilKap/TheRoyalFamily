#pragma once
#include "Piece.h"
#include <string>

namespace TheRoyalFamily
{
    class Pawn :
        public Piece
    {  
    public:
        Pawn(char file, int rank, char colour, char code = 'p');
        void move(std::string target_pos);
    };
}
