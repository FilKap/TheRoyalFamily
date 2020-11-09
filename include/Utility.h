/*	
	Utility functions (like editing console)
*/

#pragma once
#include <string>
#include <windows.h>


namespace TheRoyalFamily
{
	class Utility
	{
	public:
		static void SetCursorPiece(const Piece* p)
		{
			COORD c;
			c.X = (p->getFile() - 'A' + 1) * 2;
			c.Y = 8 - p->getRank();
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
		}
		static void SetWhiteText(void)		// with aqua background
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 63);
		}
		static void SetBlackText(void)		// with aqua background
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 48);
		}
	};
}
