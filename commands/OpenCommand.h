#pragma once

#include "Command.h"

class Hero;

class OpenCommand : public Command
{
private:
	const string item;
public:
	OpenCommand(Hero*, const string& item);
	~OpenCommand() override;
	void Execute() override;
};
