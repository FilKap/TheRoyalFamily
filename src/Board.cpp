#include "Board.h"
#include <iostream>

using namespace TheRoyalFamily;

void Board::print()
{
	for (auto i : ranks)
		std::cout << i << std::endl;
}

