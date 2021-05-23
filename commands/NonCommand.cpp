#include "NonCommand.h"


NonCommand::NonCommand(): AbstractCommand(nullptr)
{
}

NonCommand::NonCommand(Hero* hero): AbstractCommand(hero)
{
}

void NonCommand::Execute()
{
}
