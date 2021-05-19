#include <iostream>
#include "Game.h"

int main()
{
	try
	{
		Game game;
		game.Start();
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
		return 1;
	}
	return 0;
}
