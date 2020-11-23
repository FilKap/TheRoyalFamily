#pragma once
#include "Piece.h"

constexpr auto ComandLine_yPos = 10;
constexpr auto ComandLine_xPos = 3;

namespace TheRoyalFamily
{
	class Utility
	{
	public:
		static void SetCursorPiece(const Piece* p);
		static void SetCursorXY(int x, int y);
		static void SetWhiteText(void);		// with aqua background
		static void SetBlackText(void);		// with aqua background
		static void SetBackground(void);	// aqua backgorund
		static void ClearCmdLine(void);	
		static void PrintArrow(void);
	};
}
