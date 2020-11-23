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

void Board::print() const
{
	print_empty();
	print_pieces();
	Utility::ClearCmdLine();
}

void Board::movePiece(std::string current_pos, std::string target_pos)
{
	for (auto& piece : mPieces)
	{
		if (piece->getPos() == current_pos) {
			piece->move(target_pos);
			break;
		}
	}
}