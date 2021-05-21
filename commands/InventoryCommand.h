#pragma once

#include "Command.h"

class Hero;

class InventoryCommand : public Command
{
public:
	InventoryCommand(Hero* hero);
	~InventoryCommand() override;
	void Execute() override;
};
