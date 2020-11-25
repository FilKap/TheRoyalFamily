#include "Piece.h"
#include "Utility.h"
#include <iostream>

using namespace TheRoyalFamily;


Piece::Piece(char file, int rank, char colour, char code) : mRank{ rank }, mFile{ file }, mColour{ colour }, mCode{ code } { }

char Piece::getColour() const { return mColour; }

int Piece::getRank() const { return mRank; }

char Piece::getFile() const { return mFile; }

std::string Piece::getPos() const
{
	std::string pos;
	pos.push_back(mFile);
	pos.push_back(mRank + '0');
	return pos;
}

void Piece::setPos(int rank, char file)
{
	mRank = rank;
	mFile = file;
}

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
