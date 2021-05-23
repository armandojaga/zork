#pragma once

#include "Command.h"

class Hero;

class TakeCommand : public Command
{
private :
	const string item;
public:
	TakeCommand(Hero* hero, const string& item);
	~TakeCommand() override;
	void Execute() override;
};
