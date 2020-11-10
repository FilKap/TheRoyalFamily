#include "Board.h"
#include "Utility.h"
#include <iostream>

using namespace TheRoyalFamily;
using std::cout, std::endl;


Board::Board() { }

void Board::print_empty() const
{
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
	Utility::SetCursorXY(0, 10);
}
