#include "DropCommand.h"

#include <iostream>

DropCommand::DropCommand(Hero* hero) : Command(hero)
{
};

void DropCommand::Execute()
{
}

DropCommand::~DropCommand() = default;
