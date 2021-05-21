#include "TakeCommand.h"

#include <iostream>

TakeCommand::TakeCommand(Hero* hero) : Command(hero)
{
};

void TakeCommand::Execute()
{
}

TakeCommand::~TakeCommand() = default;
