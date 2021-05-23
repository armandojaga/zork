#include "GoCommand.h"

GoCommand::GoCommand(Hero* hero, const Direction& dir) : Command(hero), dir(dir)
{
}

void GoCommand::Execute()
{
	hero->go(this->dir);
}

GoCommand::~GoCommand() = default;
