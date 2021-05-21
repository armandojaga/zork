#include "AttackCommand.h"

#include <iostream>

AttackCommand::AttackCommand(Hero* hero) : Command(hero)
{
};

void AttackCommand::Execute()
{
}

AttackCommand::~AttackCommand() = default;
