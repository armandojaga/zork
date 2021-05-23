#ifndef ZORK_COMMANDS_NON_COMMAND_H
#define ZORK_COMMANDS_NON_COMMAND_H

#include "AbstractCommand.h"

class Hero;

class NonCommand : public AbstractCommand
{
public:
	NonCommand();
	NonCommand(Hero* hero);
	NonCommand(const NonCommand&) = delete;
	NonCommand& operator =(const NonCommand&) = delete;
	NonCommand(NonCommand&&) = delete;
	NonCommand& operator=(NonCommand&&) = delete;

	~NonCommand() override = default;

	void Execute() override;
};

#endif  //ZORK_COMMANDS_NON_COMMAND_H
