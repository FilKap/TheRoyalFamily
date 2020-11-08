#pragma once
#include <vector>
#include <map>
#include <string>
#include "Piece.h"
#include "Pawn.h"

using std::vector;

namespace TheRoyalFamily
{
	class Board
	{
	private:
		const vector<char> files{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
		const vector<int> ranks{ 1, 2, 3, 4, 5, 6, 7, 8 };
		std::map<std::string, Piece*> mPieces {
			{"wP1", new Pawn('A', 7, 'w')}, 
			{"bP1", new Pawn('A', 2, 'b')}
		};
		void print_empty();
		void print_pieces();
	public:
		Board();
		void print();
	};
}
