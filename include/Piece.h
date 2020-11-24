#pragma once
#include <string>

namespace TheRoyalFamily
{
	class iPiece
	{
	public:
		virtual void move(std::string target_pos) = 0;
		virtual bool canCapture(std::string pos) const = 0;
		virtual void simpleMove(std::string pos) = 0;
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
		int getRank() const;
		char getFile() const;
		char getColour() const; 
		std::string getPos() const;
		void setRank(int rank);
		void setFile(char file);
		void print() const;
		virtual ~Piece();
	};
}
