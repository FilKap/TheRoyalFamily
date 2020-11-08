#pragma once

namespace TheRoyalFamily
{
	class iPiece
	{
	public:
		virtual void move(char rank, int file) = 0;
		virtual void print() = 0;
	};


	class Piece : 
		public iPiece
	{
	protected:
		char mRank{ };
		int mFile{ };
		char mColour{ };
		char mCode{ };
	public:	
		Piece(char rank, int file, char colour, char code) : mRank{ rank }, mFile{ file }, mColour{ colour }, mCode{ code } { }
		char getRank() const { return mRank; }
		int getFile() const { return mFile; } 
	};
}
