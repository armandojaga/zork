#pragma once

#include "Command.h"

class Hero;

class EmptyCommand : public Command
{
public:
	EmptyCommand();
	EmptyCommand(Hero* hero);
	~EmptyCommand() override;
	void Execute() override;
};
