#include "GoCommand.h"

#include <iostream>

GoCommand::GoCommand(Hero* hero) : Command(hero)
{
}

void GoCommand::Execute()
{
}

GoCommand::~GoCommand() = default;
