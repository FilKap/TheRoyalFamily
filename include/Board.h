#pragma once
#include <vector>

using std::vector;

namespace TheRoyalFamily
{
	class Board
	{
	private:
		const vector<char> files{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
		const vector<int> ranks{ 1, 2, 3, 4, 5, 6, 7, 8 };
	public:
		Board() { };
		void print();
	};
}
