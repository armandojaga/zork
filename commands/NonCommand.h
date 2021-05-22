#pragma once

#include "Command.h"

class Hero;

class NonCommand : public Command
{
public:
	NonCommand();
	NonCommand(Hero* hero);
	~NonCommand() override;
	void Execute() override;
};
