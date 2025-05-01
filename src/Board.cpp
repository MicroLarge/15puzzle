#include "Board.hpp"
#include "Random.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>

Board::Board()
{
	std::vector<short int> numberQueue{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	std::shuffle(numberQueue.begin(), numberQueue.end(), Random::mt);
	for (int i{ 0 }; i < 4; ++i)
	{
		for (int j{ 0 }; j < 4; ++j)
		{
			m_board[i][j] = numberQueue.back();
			if (m_board[i][j] == 0) m_position = std::make_pair(i, j);
			numberQueue.pop_back();
		}
	}
	
}

Board::Board(bool solved)
{
	int iterator{};
	if (solved)
	{
		for (int i{ 0 }; i < 4; ++i)
		{
			for (int j{ 0 }; j < 4; ++j)
			{
				m_board[i][j] = ++iterator;
			}
		}
		m_board[3][3] = 0;
		m_position = std::make_pair(3, 3);
	}
}

void Board::print()
{
	system("cls");
	for (int i{ 0 }; i < 4; ++i)
	{
		for (int j{ 0 }; j < 4; ++j)
		{
			if (m_board[i][j]) std::cout << m_board[i][j] << '\t';
			else std::cout << " \t";
		}
		std::cout << '\n';
	}
}

bool Board::quitMenu() //Returns true if the player chose "yes", false otherwise.
{
	system("cls");
	std::cout << "Are you sure you want to quit playing? You will lose your progress.\n";
	std::cout << "Yes (Y) or No (N): ";
	int input{};
	do 
	{
		input = _getch();
	} while (input != Key::YES && input != Key::NO);
	if (input == Key::YES) return true;
	return false;
}

bool Board::hasWon()
{
	if (*this == Board{ true }) return true;
	return false;
}


bool Board::inBounds(int i, int j)
{
	return (i >= 0 && j >= 0 && i < 4 && j < 4);
}

void Board::move(int i, int j)
{
	if (inBounds(i, j))
	{
		std::swap(m_board[m_position.first][m_position.second], m_board[i][j]);
		m_position.first = i;
		m_position.second = j;
	}
}

bool operator==(const Board& b1, const Board& b2)
{
	for (int i{ 0 }; i < 4; ++i)
	{
		for (int j{ 0 }; j < 4; ++j)
		{
			if (b1.m_board[i][j] != b2.m_board[i][j]) return false;
		}
	}
	if (b1.m_position != b2.m_position) return false;
	return true;
}

bool Board::play()
{
	int input{};
	print();

	do {
		input = _getch();
	} while (input != Key::ARROW && input != Key::Q);

	if (input == Key::Q)
	{
		if (quitMenu()) return false;
		return true;
	}

	input = _getch();

	switch (input)
	{
		case Key::UP: move(m_position.first + 1, m_position.second); break; //Swaps with the unit below
		case Key::DOWN: move(m_position.first - 1, m_position.second); break; //Swaps with the unit above
		case Key::LEFT: move(m_position.first, m_position.second + 1); break; //Swaps with the unit to the right
		case Key::RIGHT: move(m_position.first, m_position.second - 1); break; //Swaps with the unit to the left
	}

	if (hasWon())
	{
		print();
		std::cout << "\n\nYou Won!";
		return false;
	}
	
	return true;
}