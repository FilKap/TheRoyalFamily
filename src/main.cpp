#include "Board.h"
#include "Utility.h"
#include <conio.h>


using namespace TheRoyalFamily;


int main()
{
	Utility::SetBackground();
	Board board;

	board.print();
	board.movePiece("A2", "B3");
	_getch();
	board.print();

	_getch();
	return 0;
}
