#pragma once

#include "Command.h"

class Hero;

class LookCommand : public Command
{
public:
	LookCommand();
	LookCommand(Hero* hero);
	~LookCommand() override;
	void Execute() override;
};
