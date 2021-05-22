#include "NonCommand.h"


NonCommand::NonCommand(): Command(nullptr)
{
}

NonCommand::NonCommand(Hero* hero): Command(hero)
{
}

NonCommand::~NonCommand()
{
}

void NonCommand::Execute()
{
}
