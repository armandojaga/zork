#ifndef ZORK_COMMANDS_DROP_COMMAND_H
#define ZORK_COMMANDS_DROP_COMMAND_H

#include "AbstractCommand.h"
#include "../characters/Hero.h"

class DropCommand : public AbstractCommand
{
private :
	const std::string item;
public:
	DropCommand(Hero* hero, std::string item);
	DropCommand(const DropCommand&) = delete;
	DropCommand& operator =(const DropCommand&) = delete;
	DropCommand(DropCommand&&) = delete;
	DropCommand& operator=(DropCommand&&) = delete;

	~DropCommand() override = default;

	void Execute() override;
};

#endif  //ZORK_COMMANDS_DROP_COMMAND_H
