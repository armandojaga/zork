#pragma once

#include "Command.h"

class ExamineCommand : public Command
{
public:
	ExamineCommand(Hero* hero);
	~ExamineCommand() override;
	void Execute() override;
};
