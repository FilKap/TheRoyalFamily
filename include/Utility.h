#pragma once
#include <string>
#include <windows.h>

namespace TheRoyalFamily
{
	class Utility
	{
	public:
		static void SetCursorPiece(Piece* p)
		{
			COORD c;
			c.X = p->getRank() - 'A' + 2;
			c.Y = p->getFile() - 1;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
		}
		static void SetWhiteText(void)		// with red background
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 63);
		}
		static void SetBlackText(void)		// with red background
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 48);
		}
	};
}
