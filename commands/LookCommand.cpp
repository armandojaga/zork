#include "LookCommand.h"

LookCommand::LookCommand(Hero* hero): AbstractCommand(hero)
{
}

void LookCommand::Execute()
{
	this->hero->getCurrentScene()->printBrief();
}
