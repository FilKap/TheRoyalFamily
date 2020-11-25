#include "Utility.h"
#include <Windows.h>
#include <iostream>

using namespace TheRoyalFamily;


void Utility::SetCursorPiece(const Piece* p)
{
	COORD c;
	c.X = (p->getFile() - 'A' + 1) * 2;
	c.Y = 8 - p->getRank();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Utility::SetCursorXY(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Utility::SetWhiteText(void)		
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 63);
}

void Utility::SetBlackText(void)		
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 48);
}

void Utility::SetBackground(void)
{
	system("Color 30");
}

void Utility::ClearCmdLine(void)
{
	Utility::SetCursorXY(ComandLine_xPos, ComandLine_yPos);
	std::cout << "        ";
	Utility::SetCursorXY(ComandLine_xPos, ComandLine_yPos);
}

void Utility::PrintArrow(void)
{
	Utility::SetCursorXY(ComandLine_xPos + 2, ComandLine_yPos);
	std::cout << " -> ";
}

bool Utility::IsOnBoard(std::string pos)
{
	char tFile = pos[0];         // tFile, tRank - target file, target rank
	int tRank = pos[1] - '0';    // -'0' to get int from char
	
	if (tFile >= 'A' && tFile <= 'H' && tRank >= 1 && tRank <= 8)
		return true;
	else
		return false;
}
