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


    inline Pawn::Pawn(char file, int rank, char colour, char code) : Piece(file, rank, colour, code) { }	// 'char code' is default

    inline void Pawn::move(std::string target_pos)
    {
        mFile = target_pos[0];
        mRank = target_pos[1] - '0';
    }
}
