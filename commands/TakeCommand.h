#pragma once

#include "Command.h"

class Hero;

class TakeCommand : public Command
{
public:
	TakeCommand(Hero* game);
	~TakeCommand() override;
	void Execute() override;
};
