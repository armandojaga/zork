#include "EmptyCommand.h"


EmptyCommand::EmptyCommand(): Command(nullptr)
{
}

EmptyCommand::EmptyCommand(Hero* hero): Command(hero)
{
}

EmptyCommand::~EmptyCommand()
{
}

void EmptyCommand::Execute()
{
	cout << "I beg your pardon?" << endl;
}
