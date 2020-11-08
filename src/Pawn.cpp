#include "Pawn.h"
#include "Utility.h"
#include <iostream>
#include <Windows.h>

using namespace TheRoyalFamily;

Pawn::Pawn(char rank, int file, char colour, char code) : Piece(rank, file, colour, code) { }


void Pawn::move(char rank, int file) { }


void Pawn::print()
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
