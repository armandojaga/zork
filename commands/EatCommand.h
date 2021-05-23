#ifndef ZORK_COMMANDS_EAT_COMMAND_H
#define ZORK_COMMANDS_EAT_COMMAND_H

#include "AbstractCommand.h"
#include "../characters/Hero.h"

class EatCommand : public AbstractCommand
{
private :
	const std::string item;
public:
	EatCommand(Hero* hero, std::string item);
	EatCommand(const EatCommand&) = delete;
	EatCommand& operator =(const EatCommand&) = delete;
	EatCommand(EatCommand&&) = delete;
	EatCommand& operator=(EatCommand&&) = delete;

	~EatCommand() override = default;

	void Execute() override;
};

#endif  //ZORK_COMMANDS_EAT_COMMAND_H
