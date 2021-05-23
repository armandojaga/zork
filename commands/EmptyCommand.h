#ifndef ZORK_COMMANDS_EMPTY_COMMAND_H
#define ZORK_COMMANDS_EMPTY_COMMAND_H

#include "AbstractCommand.h"

class Hero;

class EmptyCommand : public AbstractCommand
{
public:
	EmptyCommand();
	EmptyCommand(Hero* hero);
	EmptyCommand(const EmptyCommand&) = delete;
	EmptyCommand& operator =(const EmptyCommand&) = delete;
	EmptyCommand(EmptyCommand&&) = delete;
	EmptyCommand& operator=(EmptyCommand&&) = delete;

	~EmptyCommand() override = default;

	void Execute() override;
};

#endif  //ZORK_COMMANDS_EMPTY_COMMAND_H
