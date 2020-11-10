#pragma once
#include <vector>
#include "Piece.h"
#include "Pawn.h"


namespace TheRoyalFamily
{
	class Board
	{
	private:
		const std::vector<char> files{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
		const std::vector<int> ranks{ 8, 7, 6, 5, 4, 3, 2, 1 };
		std::vector<Piece*> mPieces {
			new Pawn('A', 2, 'w'), 
			new Pawn('B', 2, 'w'),
			new Pawn('C', 2, 'w'),
			new Pawn('A', 7, 'b')
		};
		void print_empty() const;
		void print_pieces() const;
	public:
		Board();
		void print() const;
	};
}
