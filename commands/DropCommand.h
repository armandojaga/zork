#pragma once

#include "Command.h"

class Hero;

class DropCommand : public Command
{
public:
	DropCommand(Hero* hero);
	~DropCommand() override;
	void Execute() override;
};
