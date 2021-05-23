#include "InventoryCommand.h"

InventoryCommand::InventoryCommand(Hero* hero): Command(hero)
{
}

InventoryCommand::~InventoryCommand()
{
}

void InventoryCommand::Execute()
{
	hero->printStats();
}
