#include "CommandParser.h"

#include <algorithm>

#include "commands/EmptyCommand.h"
#include "commands/GoCommand.h"
#include "commands/LookCommand.h"

string CommandPaser::ToUpper(string& str) const
{
	transform(str.begin(), str.end(), str.begin(), toupper);
	return str;
}

CommandPaser::CommandPaser() = default;

Command* CommandPaser::Parse(vector<string>& args, Hero* hero) const
{
	if (args.empty())
	{
		return new EmptyCommand();
	}
	Command* command = nullptr;
	string userCommand = args[0];
	args.erase(args.begin());
	ToUpper(userCommand);
	CommandType type = Command::GetCommand(userCommand);
	switch (type)
	{
	case GO:
		{
			userCommand = args[0];
			ToUpper(userCommand);
			Direction dir = Path::DirectionFromName(userCommand);
			if (dir != WRONG)
			{
				command = new GoCommand(hero, dir);
			}
		}
		break;
	case ATTACK: break;
	case EXAMINE: break;
	case TAKE: break;
	case DROP: break;
	case INVENTORY: break;
	case HELP: break;
	case LOOK:
		if (args.empty()) {
			command = new LookCommand();
		}else
		{
			cout << "You can't look at that" << endl;
		}
		break;
	case OPEN: break;
	case EMPTY:
	default:
		{
			const Direction d = Path::DirectionFromName(userCommand);
			if (d != WRONG)
			{
				command = new GoCommand(hero, d);
			}
		}
	}
	args.clear();
	if (!command)
	{
		command = new EmptyCommand();
	}
	return command;
}

CommandPaser::~CommandPaser() = default;
