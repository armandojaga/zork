#ifndef ZORK_COMMANDS_LOOK_COMMAND_H
#define ZORK_COMMANDS_LOOK_COMMAND_H

#include "AbstractCommand.h"

class Hero;

class LookCommand : public AbstractCommand
{
public:
	LookCommand(Hero* hero);
	LookCommand(const LookCommand&) = delete;
	LookCommand& operator =(const LookCommand&) = delete;
	LookCommand(LookCommand&&) = delete;
	LookCommand& operator=(LookCommand&&) = delete;

	~LookCommand() override = default;

	void Execute() override;
};

#endif  //ZORK_COMMANDS_LOOK_COMMAND_H
