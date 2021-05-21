#pragma once

#include "Command.h"

class Hero;

class AttackCommand : public Command
{
public:
	AttackCommand(Hero* hero);
	~AttackCommand() override;
	void Execute() override;
};
