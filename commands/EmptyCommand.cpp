#include <iostream>

#include "EmptyCommand.h"

using namespace std;

EmptyCommand::EmptyCommand(): AbstractCommand(nullptr)
{
}

EmptyCommand::EmptyCommand(Hero* hero): AbstractCommand(hero)
{
}

void EmptyCommand::Execute()
{
	cout << "I beg your pardon?" << endl;
}
