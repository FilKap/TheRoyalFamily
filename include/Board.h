#pragma once
#include <vector>
#include <string>
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"

namespace TheRoyalFamily
{
	class Board
	{
	private:
		Board();
		const std::vector<char> files{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
		const std::vector<int> ranks{ 8, 7, 6, 5, 4, 3, 2, 1 };
		std::vector<Piece*> mPieces{
			new Pawn('A', 2, 'w'),
			new Pawn('B', 2, 'w'),
			new Pawn('C', 2, 'w'),
			new Pawn('D', 2, 'w'),
			new Pawn('E', 2, 'w'),
			new Pawn('F', 2, 'w'),
			new Pawn('G', 2, 'w'),
			new Pawn('H', 2, 'w'),
			new Pawn('A', 7, 'b'),
			new Pawn('B', 7, 'b'),
			new Pawn('C', 7, 'b'),
			new Pawn('D', 7, 'b'),
			new Pawn('E', 7, 'b'),
			new Pawn('F', 7, 'b'),
			new Pawn('G', 7, 'b'),
			new Pawn('H', 7, 'b'),
			new Rook('A', 1, 'w'),
			new Rook('H', 1, 'w'),
			new Rook('A', 8, 'b'),
			new Rook('H', 8, 'b')
		};
		void print_empty() const;
		void print_pieces() const;
		void capture(std::string pos);
	public:
		static Board& getBoard();
		void print() const;
		void movePiece(std::string current_pos, std::string target_pos);
		bool isFree(std::string pos) const;
	};
}
