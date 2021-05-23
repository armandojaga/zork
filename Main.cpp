#include <iostream>
#include "Game.h"

int main()
{
	try
	{
		const Game game;
		game.Start();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return EXIT_SUCCESS;
}
