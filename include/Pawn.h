#pragma once
#include "Piece.h"
#include <string>

extern char turn;

namespace TheRoyalFamily
{
    class Pawn :
        public Piece
    {  
    public:
        Pawn(char file, int rank, char colour, char code = 'p');
        void move(std::string target_pos);
        bool canCapture(std::string pos) const;
        void simpleMove(std::string pos);
    };
    
   
    inline Pawn::Pawn(char file, int rank, char colour, char code) : Piece(file, rank, colour, code) { }	// 'char code' is default

    /// <summary>
    /// Changing the position of pawn
    /// </summary>
    /// <param name="target_pos">
    ///  - target_pos[0]-file; target_pos[1]-rank;
    /// </param>
    inline void Pawn::move(std::string target_pos)
    {
        char tFile = target_pos[0];         // tFile, tRank - target file, target rank
        int tRank = target_pos[1] - '0';    // -'0' to get int from char

        if (mColour == 'w')       // white pawn 
        {
            // move pawn by one square forward (up on board)
            if (tFile == mFile && tRank == mRank + 1 && tRank <= 8) {           // if file is the same and rank is one greater and isn't over 8 
                mFile = tFile;
                mRank = tRank;
                turn = 'b';
            }
            // move pawn by two square forward if it's a firt its move
            else if (tFile == mFile && tRank == mRank + 2 && mRank == 2) {      // if file is the same and rank is two greater and isn't over 8 
                mFile = tFile;
                mRank = tRank;
                turn = 'b';
            }
        }

        else if (mColour == 'b')       // black pawn 
        {
            // move pawn by one square forward (up on board)
            if (tFile == mFile && tRank == mRank - 1 && tRank >= 1) {           // if file is the same and rank is one less and isn't less then 1 
                mFile = tFile;
                mRank = tRank;
                turn = 'w';
            }
            // move pawn by two square forward if it's a firt its move
            else if (tFile == mFile && tRank == mRank - 2 && mRank == 7) {      // if file is the same and rank is two less and isn't less then 1 
                mFile = tFile;
                mRank = tRank;
                turn = 'w';
            }
        }
    }

    inline bool Pawn::canCapture(std::string pos) const
    {
        char tFile = pos[0];         
        int tRank = pos[1] - '0';    

        if (mColour == 'w')        // white pawn
        {
            if ((tFile == mFile - 1 || tFile == mFile + 1) && tRank == mRank + 1) {  // try to capture
                return true;
            }
            else
                return false;
        }

        else                      // black pawn
        {
            if ((tFile == mFile - 1 || tFile == mFile + 1) && tRank == mRank - 1) {  // try to capture
                return true;
            }
            else
                return false;
        }
    }

    inline void Pawn::simpleMove(std::string pos)
    {
        char tFile = pos[0];
        int tRank = pos[1] - '0';
        mFile = tFile;
        mRank = tRank;
        if (turn == 'w')
            turn = 'b';
        else
            turn = 'w';
    }
}
