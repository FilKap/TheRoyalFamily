#include "Board.h"
#include "Utility.h"
#include <conio.h>
#include <iostream>
#include <string>


using namespace TheRoyalFamily;
using std::string, std::cout, std::cin, std::endl;

char turn{ 'w' };

int main()
{
	Utility::SetBackground();
	Board board;

	while (1)
	{
		if (turn == 'w')
			Utility::SetWhiteText();
		else
			Utility::SetBlackText();

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
