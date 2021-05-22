#pragma once

#include "Command.h"

class GoCommand : public Command
{
private:
	Direction dir;
public:
	GoCommand(Hero* hero, const Direction& dir);
	~GoCommand() override;
	void Execute() override;
};
