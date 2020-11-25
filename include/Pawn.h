#pragma once
#include "Piece.h"
#include "Utility.h"
#include <string>

extern char turn;

namespace TheRoyalFamily
{
    class Pawn :
        public Piece
    {  
    public:
        Pawn(char file, int rank, char colour, char code = 'p');
        bool move(std::string target_pos);
    };
    
   
    inline Pawn::Pawn(char file, int rank, char colour, char code) : Piece(file, rank, colour, code) { }	// 'char code' is default

    /// <summary>
    /// Changing the position of pawn
    /// </summary>
    /// <param name="target_pos">
    ///  - target_pos[0]-file; target_pos[1]-rank;
    /// </param>
    inline bool Pawn::move(std::string target_pos)
    {
        char tFile = target_pos[0];         // tFile, tRank - target file, target rank
        int tRank = target_pos[1] - '0';    // -'0' to get int from char

        if (mColour == 'w')       // white pawn 
        {
            // move pawn by one square forward (up on board)
            if (tFile == mFile && tRank == mRank + 1 && Utility::IsOnBoard(target_pos)) {    // if tFile is the same and tRank is one greater and target_pos is on board
                setPos(tRank, tFile);
                return true;
            }
            // move pawn by two square forward if it's a firt its move
            else if (tFile == mFile && tRank == mRank + 2 && mRank == 2) {        // if tFile is the same and tRank is two greater and equals 2
                setPos(tRank, tFile);
                return true;
            }
            // capturing (one square diagonally)
            else if ((tFile == mFile + 1 || tFile == mFile - 1) && tRank == mRank + 1 && Utility::IsOnBoard(target_pos))  // if tFile is one less or greater and tRank is one greater and target_pos is on board
            {
                setPos(tRank, tFile);
                return true;
            }
            else
                return false;
        }

        else                      // black pawn 
        {
            // move pawn by one square forward (up on board)
            if (tFile == mFile && tRank == mRank - 1 && Utility::IsOnBoard(target_pos)) {      // if tFile is the same and tRank is one greater and target_pos is on board 
                setPos(tRank, tFile);
                return true;
            }
            // move pawn by two square forward if it's a firt its move
            else if (tFile == mFile && tRank == mRank - 2 && mRank == 7) {       // if tFile is the same and tRank is two less and equals 7
                setPos(tRank, tFile);
                return true;
            }
            // capturing (one square diagonally)
            else if ((tFile == mFile + 1 || tFile == mFile - 1) && tRank == mRank - 1 && Utility::IsOnBoard(target_pos))    // if tFile is one less or greater and tRank is one less and target_pos is on board
            {
                setPos(tRank, tFile);
                return true;
            }
            else
                return false;
        }
    }
}
