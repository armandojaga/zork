#include "HelpCommand.h"

HelpCommand::HelpCommand() : Command(nullptr)
{
}

HelpCommand::HelpCommand(Hero* hero): Command(hero)
{
}

HelpCommand::~HelpCommand()
{
}

void HelpCommand::Execute()
{
}
