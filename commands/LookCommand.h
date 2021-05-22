#pragma once

#include "Command.h"

class Hero;

class LookCommand : public Command
{
public:
	LookCommand(Hero* hero);
	~LookCommand() override;
	void Execute() override;
};
