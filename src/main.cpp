#include "Board.h"
#include "Utility.h"
#include <conio.h>

using namespace TheRoyalFamily;


int main()
{
	Utility::SetBackground();
	Board board;

	board.print();

	_getch();
	return 0;
}
