#pragma once

#include "Command.h"

class Hero;

class EatCommand : public Command
{
private :
	const string item;
public:
	EatCommand(Hero* hero, const string& item);
	~EatCommand() override;
	void Execute() override;
};
