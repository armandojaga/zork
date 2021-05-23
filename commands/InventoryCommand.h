#ifndef ZORK_COMMANDS_INVENTORY_COMMAND_H
#define ZORK_COMMANDS_INVENTORY_COMMAND_H

#include "AbstractCommand.h"

class Hero;

class InventoryCommand : public AbstractCommand
{
public:
	InventoryCommand(Hero* hero);
	InventoryCommand(const InventoryCommand&) = delete;
	InventoryCommand& operator =(const InventoryCommand&) = delete;
	InventoryCommand(InventoryCommand&&) = delete;
	InventoryCommand& operator=(InventoryCommand&&) = delete;

	~InventoryCommand() override = default;

	void Execute() override;
};

#endif  //ZORK_COMMANDS_INVENTORY_COMMAND_H
