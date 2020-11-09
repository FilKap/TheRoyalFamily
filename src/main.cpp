#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Board.h"
#include "Utility.h"

using namespace TheRoyalFamily;

int main()
{
	system("Color 30");		// set aqua background

	Board board;
	board.print();

	_getch();
	return 0;
}