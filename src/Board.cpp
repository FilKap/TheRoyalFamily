#include "Board.h"
#include "Pawn.h"
#include <iostream>
#include<windows.h>

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
	for (auto const &pair : mPieces)
		pair.second->print();
}



void Board::print() const
{
	COORD c;
	c.X = 0;
	c.Y = 10;

	Board::print_empty();
	Board::print_pieces();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}