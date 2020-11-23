#include "Board.h"
#include "Utility.h"
#include <conio.h>
#include <iostream>
#include <string>


using namespace TheRoyalFamily;
using std::string, std::cout, std::cin, std::endl;

int main()
{
	Utility::SetBackground();
	Board board;

	while (1)
	{
		string current_pos;
		string target_pos;
		cin >> current_pos;
		Utility::PrintArrow();
		cin >> target_pos;
		board.movePiece(current_pos, target_pos);
		board.print();
	}


	return 0;
}
