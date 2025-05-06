#pragma once
#include <utility>
#include <vector>
#include "Random.hpp"

namespace Key
{
	constexpr int ENTER{ 13 };
	constexpr int YES{ 121 };
	constexpr int NO{ 110 };

	constexpr int Q{ 113 };
	constexpr int ARROW{ 224 };

	constexpr int UP{ 72 };
	constexpr int DOWN{ 80 };
	constexpr int LEFT{ 75 };
	constexpr int RIGHT{ 77 };
};

class Board
{
private:
	short int m_board[4][4]{};

	unsigned long long m_moves{};

	std::pair<int, int> m_position{};

	bool inBounds(int i, int j);
	void move(int i, int j);

	void print();
	bool quitMenu();
	bool hasWon();

	Board(bool solved);
	//friend int main();
	friend bool operator==(const Board& b1, const Board& b2);
public:
	Board();
	bool play();
};

// Added check to see if the puzzle is solvable
bool checkSolvable(std::vector<short int> &sequence);
