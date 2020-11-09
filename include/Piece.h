#pragma once

namespace TheRoyalFamily
{
	class iPiece
	{
	public:
		virtual void move(char rank, int file) = 0;
		virtual void print() const = 0;
		virtual ~iPiece() { }
	};


	class Piece : 
		public iPiece
	{
	protected:
		int mRank{ };
		char mFile{ };
		const char mColour{ };
		const char mCode{ };		// to display on board
	public:	
		Piece(char file, int rank, char colour, char code) : mRank{ rank }, mFile{ file }, mColour{ colour }, mCode{ code } { }
		int getRank() const { return mRank; }
		char getFile() const { return mFile; } 
		virtual ~Piece() { }
	};
}
