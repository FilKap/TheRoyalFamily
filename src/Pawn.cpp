#include <iostream>
#include <Windows.h>
#include "Pawn.h"
#include "Utility.h"


using namespace TheRoyalFamily;


Pawn::Pawn(char file, int rank, char colour, char code) : Piece(file, rank, colour, code) { }	// code is default


void Pawn::move(char rank, int file) { }


void Pawn::print() const
{
	Utility::SetCursorPiece(this);

	if (mColour == 'w') {
		Utility::SetWhiteText();
		std::cout << mCode;
		Utility::SetBlackText();
	}
	else if (mColour == 'b') {
		std::cout << mCode;
	}
}
