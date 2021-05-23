#include <iostream>
#include <algorithm>

#include "CommandParser.h"
#include "../commands/AttackCommand.h"
#include "../commands/DropCommand.h"
#include "../commands/EatCommand.h"
#include "../commands/EmptyCommand.h"
#include "../commands/GoCommand.h"
#include "../commands/HelpCommand.h"
#include "../commands/InventoryCommand.h"
#include "../commands/LookCommand.h"
#include "../commands/OpenCommand.h"
#include "../commands/NonCommand.h"
#include "../commands/TakeCommand.h"

using namespace std;

void CommandParser::ToUpper(string& str) const
{
	transform(str.begin(), str.end(), str.begin(), toupper);
}

CommandParser::CommandParser() = default;

AbstractCommand* CommandParser::Parse(vector<string>& args, Hero* hero) const
{
	if (args.empty())
	{
		return new EmptyCommand();
	}
	AbstractCommand* command = nullptr;
	string userCommand = args[0];
	args.erase(args.begin());
	ToUpper(userCommand);
	const eCommandType type = AbstractCommand::GetCommand(userCommand);
	switch (type)
	{
	case GO:
		if (args.empty())
		{
			cout << "Where do you want to go?" << endl;
			command = new NonCommand();
		}
		else
		{
			userCommand = args[0];
			ToUpper(userCommand);
			const eDirection dir = Path::DirectionFromName(userCommand);
			if (dir != WRONG)
			{
				command = new GoCommand(hero, dir);
			}
		}
		break;
	case ATTACK:
		if (args.empty())
		{
			cout << "Which foe do you want to attack?" << endl;
			command = new NonCommand();
		}
		else
		{
			command = new AttackCommand(hero, args);
		}
		break;
	case TAKE:
		if (args.empty())
		{
			cout << "What do you want to take?" << endl;
			command = new NonCommand();
		}
		else
		{
			userCommand = args[0];
			command = new TakeCommand(hero, userCommand);
		}
		break;
	case DROP:
		if (args.empty())
		{
			cout << "What do you want to drop?" << endl;
			command = new NonCommand();
		}
		else
		{
			userCommand = args[0];
			command = new DropCommand(hero, userCommand);
		}
		break;
	case EAT:
		if (args.empty())
		{
			cout << "What do you want to eat?" << endl;
			command = new NonCommand();
		}
		else
		{
			userCommand = args[0];
			command = new EatCommand(hero, userCommand);
		}
		break;
	case INVENTORY:
		command = new InventoryCommand(hero);
		break;
	case HELP:
		command = new HelpCommand();
		break;
	case LOOK:
		if (args.empty())
		{
			command = new LookCommand(hero);
		}
		else
		{
			cout << "You can't look at that" << endl;
			command = new NonCommand();
		}
		break;
	case OPEN:
		if (args.empty() || args.size() > 1)
		{
			cout << "What do you want to open?" << endl;
			command = new NonCommand();
		}
		else
		{
			userCommand = args[0];
			command = new OpenCommand(hero, userCommand);
		}
		break;
	case EMPTY:
		{
			const eDirection d = Path::DirectionFromName(userCommand);
			if (d != WRONG)
			{
				command = new GoCommand(hero, d);
			}
		}
		break;
	}
	args.clear();
	if (!command)
	{
		command = new EmptyCommand();
	}
	return command;
}
