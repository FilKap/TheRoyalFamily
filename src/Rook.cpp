#include "Rook.h"
#include "Board.h"
#include "Utility.h"

using namespace TheRoyalFamily;

Rook::Rook(char file, int rank, char colour, char code) : Piece(file, rank, colour, code) { }	// 'char code' is default

bool Rook::checkSquaresAreFree(std::string target_pos) const
{
    std::string pos = this->getPos();
    Board& board = Board::getBoard();
    char tFile = target_pos[0];         // tFile, tRank - target file, target rank
    int tRank = target_pos[1] - '0';    // -'0' to get int from char
    char dir{ };

    if (tFile - mFile > 0)              // check the rook move direction
        dir = 'R';
    else if (tFile - mFile < 0)
        dir = 'L';
    else if (tRank - mRank > 0)
        dir = 'U';
    else if (tRank - mRank < 0)
        dir = 'D';

    while (pos != target_pos)
    {
        if (dir == 'R')                                 // depend of direction check right squares
            pos = Utility::MovePos(pos, 1, 0);
        else if (dir == 'L')
            pos = Utility::MovePos(pos, -1, 0);
        else if (dir == 'U')
            pos = Utility::MovePos(pos, 0, 1);
        else if (dir == 'D')
            pos = Utility::MovePos(pos, 0, -1);

        if (!board.isFree(pos) && pos != target_pos)    // don't check target_pos
            return false;
    }
    return true;
}

bool Rook::move(std::string target_pos)
{
    Board& board = Board::getBoard();
    char tFile = target_pos[0];         // tFile, tRank - target file, target rank
    int tRank = target_pos[1] - '0';    // -'0' to get int from char

    // move rook regular
    if ( (tFile == mFile || tRank == mRank) &&                               // if file or rank is same
         Utility::IsOnBoard(target_pos) &&                                   // and target_pos is on board 
         checkSquaresAreFree(target_pos) && board.isFree(target_pos) )       // and all squares involved are free
    {
        setPos(tRank, tFile);                                                //move
        return true;
    }

    // capturing
    else if ( (tFile == mFile || tRank == mRank) &&                          // if file or rank is same    
              checkSquaresAreFree(target_pos) &&                             // and all squares involved are free
              !board.isFree(target_pos) &&                                   // but on target_pos is a piece
              board.isEnemy(target_pos) )                                    // in diffrent colour
    {                                       
        setPos(tRank, tFile);                                                // move
        return true;
    }

    else 
       return false;
}
