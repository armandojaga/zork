#include "InventoryCommand.h"

InventoryCommand::InventoryCommand(Hero* hero): AbstractCommand(hero)
{
}

void InventoryCommand::Execute()
{
	hero->printStats();
}
