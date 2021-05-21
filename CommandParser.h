#pragma once
#include <list>

#include "commands/Command.h"

class CommandPaser
{
private:
	string ToUpper(string&) const;
public:
	CommandPaser();
	Command* Parse(list<string>& args, Hero*);
	~CommandPaser();
};
