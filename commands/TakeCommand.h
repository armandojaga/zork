#ifndef ZORK_COMMANDS_TAKE_COMMAND_H
#define ZORK_COMMANDS_TAKE_COMMAND_H

#include "AbstractCommand.h"

class Hero;

class TakeCommand : public AbstractCommand
{
private :
	const std::string item;
public:
	TakeCommand(Hero* hero, std::string item);
	TakeCommand(const TakeCommand&) = delete;
	TakeCommand& operator =(const TakeCommand&) = delete;
	TakeCommand(TakeCommand&&) = delete;
	TakeCommand& operator=(TakeCommand&&) = delete;

	~TakeCommand() override = default;

	void Execute() override;
};

#endif  //ZORK_COMMANDS_TAKE_COMMAND_H
