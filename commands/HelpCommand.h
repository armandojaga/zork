#ifndef ZORK_COMMANDS_HELP_COMMAND_H
#define ZORK_COMMANDS_HELP_COMMAND_H

#include "AbstractCommand.h"

class Hero;

class HelpCommand : public AbstractCommand
{
public:
	HelpCommand();
	HelpCommand(Hero* hero);
	HelpCommand(const HelpCommand&) = delete;
	HelpCommand& operator =(const HelpCommand&) = delete;
	HelpCommand(HelpCommand&&) = delete;
	HelpCommand& operator=(HelpCommand&&) = delete;

	~HelpCommand() override = default;

	void Execute() override;
};

#endif  //ZORK_COMMANDS_HELP_COMMAND_H
