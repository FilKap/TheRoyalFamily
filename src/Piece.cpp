#include "Piece.h"
#include "Utility.h"
#include <iostream>

using namespace TheRoyalFamily;


Piece::Piece(char file, int rank, char colour, char code) : mRank{ rank }, mFile{ file }, mColour{ colour }, mCode{ code } { }

int Piece::getRank() const { return mRank; }

char Piece::getFile() const { return mFile; }

void Piece::setRank(int rank) { mRank = rank; }

void Piece::setFile(char file) { mFile = file; }

void Piece::print() const
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

Piece::~Piece() { }
