#ifndef ZORK_COMMANDS_ATTACK_COMMAND_H
#define ZORK_COMMANDS_ATTACK_COMMAND_H

#include "AbstractCommand.h"
#include "../characters/Hero.h"


class AttackCommand : public AbstractCommand
{
private:
	const std::vector<std::string> params;
public:
	AttackCommand(Hero* hero, const std::vector<std::string>& params);
	AttackCommand(const AttackCommand&) = delete;
	AttackCommand& operator =(const AttackCommand&) = delete;
	AttackCommand(AttackCommand&&) = delete;
	AttackCommand& operator=(AttackCommand&&) = delete;

	~AttackCommand() override = default;

	void Execute() override;
};

#endif  //ZORK_COMMANDS_ATTACK_COMMAND_H
