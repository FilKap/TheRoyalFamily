#pragma once
#include <string>

namespace TheRoyalFamily
{
	class iPiece
	{
	public:
		virtual bool move(std::string target_pos) = 0;
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
		Piece(char file, int rank, char colour, char code);
		char getColour() const; 
		int getRank() const;
		char getFile() const;
		std::string getPos() const;
		void setPos(int rank, char file);
		void print() const;
		virtual ~Piece();
	};
}
