#pragma once

#include "Command.h"

class GoCommand : public Command
{
public:
	GoCommand(Hero* hero);
	~GoCommand() override;
	void Execute() override;
};
