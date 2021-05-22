#pragma once
#include <list>

#include "commands/Command.h"

class CommandPaser
{
private:
	string ToUpper(string&) const;
public:
	CommandPaser();
	Command* Parse(vector<string>& args, Hero*) const;
	~CommandPaser();
};
