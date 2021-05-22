#pragma once

#include "Command.h"

class Hero;

class HelpCommand : public Command
{
public:
	HelpCommand();
	HelpCommand(Hero* hero);
	~HelpCommand() override;
	void Execute() override;
};
