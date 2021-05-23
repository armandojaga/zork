#include "LookCommand.h"

LookCommand::LookCommand(Hero* hero): Command(hero)
{
}

LookCommand::~LookCommand()
{
}

void LookCommand::Execute()
{
	this->hero->getCurrentScene()->printBrief();
}
