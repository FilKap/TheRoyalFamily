#include "Pawn.h"
#include <string>

using namespace TheRoyalFamily;


Pawn::Pawn(char file, int rank, char colour, char code) : Piece(file, rank, colour, code) { }	// 'char code' is default

/*
	string target_pos - position on board, for example "A1" 
*/
void Pawn::move(std::string target_pos)
{
	mFile = target_pos[0];
	mRank = target_pos[1] - '0';

}
