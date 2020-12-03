#include "Rook.h"

using namespace TheRoyalFamily;

Rook::Rook(char file, int rank, char colour, char code) : Piece(file, rank, colour, code) { }	// 'char code' is default

bool Rook::move(std::string target_pos) { return false; }
