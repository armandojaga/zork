#ifndef ZORK_COMMANDS_GO_COMMAND_H
#define ZORK_COMMANDS_GO_COMMAND_H

#include "AbstractCommand.h"

class GoCommand : public AbstractCommand
{
private:
	eDirection dir;
public:
	GoCommand(Hero* hero, const eDirection& dir);
	GoCommand(const GoCommand&) = delete;
	GoCommand& operator =(const GoCommand&) = delete;
	GoCommand(GoCommand&&) = delete;
	GoCommand& operator=(GoCommand&&) = delete;

	~GoCommand() override = default;

	void Execute() override;
};

#endif  //ZORK_COMMANDS_GO_COMMAND_H
