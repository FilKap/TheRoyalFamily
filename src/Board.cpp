#include "Board.h"
#include "Utility.h"
#include <iostream>
#include <string>

using namespace TheRoyalFamily;
using std::cout, std::endl;


Board::Board() 
{
	print();
}

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

bool Board::isFreeSquare(std::string pos) const
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
	auto x = std::remove_if(mPieces.begin(), mPieces.end(), [pos](Piece* piece) { return piece->getPos() == pos; });
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
		if (piece->getPos() == current_pos) 
		{	
			if (piece->getColour() != turn)				// colour check
				break;
			else if (!isFreeSquare(target_pos)) {		// if square is busy
				if (piece->canCapture(target_pos)) {	// try capture
					capture(target_pos);
					piece->simpleMove(target_pos);		// need edit
					break;
				}
				else
					break;
			}
			else {
				piece->move(target_pos);				// try move
				break;
			}
		}
	}
}
	