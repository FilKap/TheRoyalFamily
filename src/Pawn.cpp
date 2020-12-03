#include "Pawn.h"
#include "Utility.h"
#include "Board.h"

using namespace TheRoyalFamily;

extern char turn;


Pawn::Pawn(char file, int rank, char colour, char code) : Piece(file, rank, colour, code) { }	// 'char code' is default

bool Pawn::move(std::string target_pos)
{
    Board& board = Board::getBoard();
    char tFile = target_pos[0];         // tFile, tRank - target file, target rank
    int tRank = target_pos[1] - '0';    // -'0' to get int from char

    if (mColour == 'w')       // white pawn 
    {

        // move pawn by one square forward (up on board)
        if ( tFile == mFile && tRank == mRank + 1 &&         // if tFile is the same and tRank is one greater
             Utility::IsOnBoard(target_pos) &&               // and target_pos is on board
             board.isFree(target_pos) )                      // and the target square is free 
        {                                          
            setPos(tRank, tFile);
            return true;
        }

        // move pawn by two square forward if it's a first move
        else if ( tFile == mFile && tRank == mRank + 2 && mRank == 2 &&      // if tFile is the same and tRank is two greater and equals 2
                  board.isFree(Utility::MovePos(target_pos, 0, -1)) &&       // and the both squares are free  
                  board.isFree(target_pos) )                                      
        {       
            setPos(tRank, tFile);
            return true;
        }

        // capturing (one square diagonally)
        else if ( (tFile == mFile + 1 || tFile == mFile - 1) && tRank == mRank + 1 &&   // if tFile is one less or greater and tRank is one greater
                  !board.isFree(target_pos) )                                           // and there is a piece at target_pos
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
        if ( tFile == mFile && tRank == mRank - 1 &&        // if tFile is the same and tRank is one greater
             Utility::IsOnBoard(target_pos) &&              // and target_pos is on board 
            board.isFree(target_pos) )                      // and the target square is free) 
            {       
                setPos(tRank, tFile);
                return true;
            }

        // move pawn by two square forward if it's a firt its move
        else if ( tFile == mFile && tRank == mRank - 2 && mRank == 7 &&           // if tFile is the same and tRank is two less and equals 7
                  board.isFree(Utility::MovePos(target_pos, 0, 1)) &&             // and the both squares are free  
                  board.isFree(target_pos) )
        {      
            setPos(tRank, tFile);
            return true;
        }

        // capturing (one square diagonally)
        else if ( (tFile == mFile + 1 || tFile == mFile - 1) && tRank == mRank - 1 &&   // if tFile is one less or greater and tRank is one less
                   !board.isFree(target_pos) )                                          // and there is a piece at target_pos
        {
            setPos(tRank, tFile);
            return true;
        }

        else
            return false;
    }
}
