#include "ExamineCommand.h"

#include <iostream>

ExamineCommand::ExamineCommand(Hero* hero) : Command(hero)
{
}

void ExamineCommand::Execute()
{
}

ExamineCommand::~ExamineCommand() = default;
