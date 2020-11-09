#pragma once
#include "Piece.h"

namespace TheRoyalFamily
{
    class Pawn :
        public Piece
    {  
    public:
        Pawn(char file, int rank, char colour, char code = 'p');
        void move(char rank, int file);
        void print() const;
    };
}
