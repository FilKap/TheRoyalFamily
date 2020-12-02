#include "Board.h"
#include "Utility.h"
#include <iostream>
#include <string>

using namespace TheRoyalFamily;
using std::cout, std::endl;

extern char turn;


Board::Board() { }

void Board::print_empty() const
{
	Utility::SetCursorXY(0, 0);
	for (auto i = 0; i < ranks.size(); i++) {
		cout << ranks[i] << " ";
		for (auto i = 0; i < files.size(); i++) {
			cout << "_ ";
		}
		cout << endl;
	}
	cout << "  ";
	for (auto i : files)
		cout << i << " ";
}

void Board::print_pieces() const
{	
	for (auto const& piece : mPieces)
		piece->print();
}

bool Board::isFreeSquare(std::string pos) const		// USELESS
{
	for (const auto& piece : mPieces)
	{
		if (piece->getPos() == pos)
			return false;
	}
	return true;
}

void Board::capture(std::string pos)	// remove Piece from pos
{
	auto x = std::remove_if(mPieces.begin(), mPieces.end(), [pos](Piece* piece) {
		if (piece->getPos() == pos && piece->getColour() != turn)			// if piece is on pos and its got diffrent colour then capture
			return true;
		else
			return false; });
}

Board& Board::getBoard()
{
	static Board board;
	return board;
}

void Board::print() const
{
	Utility::SetBlackText();
	print_empty();
	print_pieces();
	Utility::ClearCmdLine();
}

void Board::movePiece(std::string current_pos, std::string target_pos)
{
	for (auto& piece : mPieces)
	{
		if (piece->getPos() == current_pos)						// chosen piece
		{	
			if (piece->getColour() == turn)						// colour check
			{
				if (piece->move(target_pos)) {					// try mvoe
					capture(target_pos);						// try capture
					turn = (turn == 'w') ? 'b' : 'w';
					break;
				}
			}
		}
	}
}
	