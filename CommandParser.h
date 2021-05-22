#pragma once
#include <list>

#include "commands/Command.h"

class CommandParser
{
private:
	string ToUpper(string&) const;
public:
	CommandParser();
	Command* Parse(vector<string>& args, Hero*) const;
	~CommandParser();
};
