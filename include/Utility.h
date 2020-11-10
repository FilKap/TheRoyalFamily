/*	
	Utility functions (like editing console)
*/

#pragma once
#include "Piece.h"


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
	};
}
