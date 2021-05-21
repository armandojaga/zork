#include "EmptyCommand.h"

EmptyCommand::EmptyCommand(Hero* hero): Command(hero)
{
}

EmptyCommand::~EmptyCommand()
{
	cout << "I beg your pardon?" << endl;
}

void EmptyCommand::Execute()
{
}
