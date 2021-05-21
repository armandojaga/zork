#include "CommandParser.h"

#include <algorithm>

#include "commands/EmptyCommand.h"

string CommandPaser::ToUpper(string& str) const
{
	transform(str.begin(), str.end(), str.begin(), toupper);
	return str;
}

CommandPaser::CommandPaser() = default;

Command* CommandPaser::Parse(list<string>& args, Hero* hero)
{
	return new EmptyCommand(hero);
}

CommandPaser::~CommandPaser() = default;
