#pragma once

#include "Command.h"

class Hero;

class AttackCommand : public Command
{
private:
	const vector<string> params;
public:
	AttackCommand(Hero* hero, const vector<string>& params);
	~AttackCommand() override;
	void Execute() override;
};
