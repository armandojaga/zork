#include "GoCommand.h"

GoCommand::GoCommand(Hero* hero, const eDirection& dir) : AbstractCommand(hero), dir(dir)
{
}

void GoCommand::Execute()
{
	hero->go(this->dir);
}
