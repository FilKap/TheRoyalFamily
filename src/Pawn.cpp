#include "Pawn.h"

using namespace TheRoyalFamily;


Pawn::Pawn(char file, int rank, char colour, char code) : Piece(file, rank, colour, code) { }	// 'char code' is default

void Pawn::move(char rank, int file) { }
