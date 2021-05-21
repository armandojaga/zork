#pragma once

#include "Command.h"

class Hero;

class OpenCommand : public Command
{
public:
	OpenCommand(Hero* hero);
	~OpenCommand() override;
	void Execute() override;
};
