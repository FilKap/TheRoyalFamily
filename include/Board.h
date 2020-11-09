#pragma once
#include <vector>
#include <map>
#include <string>
#include "Piece.h"
#include "Pawn.h"


namespace TheRoyalFamily
{
	class Board
	{
	private:
		const std::vector<char> files{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
		const std::vector<int> ranks{ 8, 7, 6, 5, 4, 3, 2, 1 };
		std::map<std::string, Piece*> mPieces {
			{"wP1", new Pawn('A', 2, 'w')}, 
			{"bP1", new Pawn('A', 7, 'b')},
			{"wP2", new Pawn('B', 2, 'w')},
		};
		void print_empty() const;
		void print_pieces() const;
	public:
		Board();
		void print() const;
	};
}
