#pragma once

#include "Command.h"

class Hero;

class DropCommand : public Command
{
private :
	const string item;
public:
	DropCommand(Hero* hero, const string& item);
	~DropCommand() override;
	void Execute() override;
};
