#include <iostream>
#include "Board.hpp"
#include <conio.h>

int main()
{
	std::cout << "Welcome to 15 Puzzle!\n";
	std::cout << "Use the arrow keys to move. Press \'Q\' to quit at any time.\n";
	std::cout << "Press Enter to start.";

	while (_getch() != Key::ENTER)
		;
	Board board;

	system("cls");
	while(board.play())
		;

	return 0;
}
