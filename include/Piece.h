#pragma once

namespace TheRoyalFamily
{
	class Piece
	{
	protected:
		char mRank{ };
		int mFile{ };
		char mColour{ };
	public:
		virtual void move(char rank, int file) = 0;
		Piece(char rank, int file, char colour) : mRank { rank }, mFile{ file }, mColour{ colour } { }
	};
}
