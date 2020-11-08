#pragma once
#include "Piece.h"

namespace TheRoyalFamily
{
    class Pawn :
        public Piece
    {  
    public:
        Pawn(char rank, int file, char colour, char code = 'P');
        void move(char rank, int file);
        void print();
    };
}
