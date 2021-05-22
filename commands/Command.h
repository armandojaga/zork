#pragma once
#include <string>
#include <unordered_map>

#include "../Hero.h"

using namespace std;

enum CommandType
{
	GO,
	ATTACK,
	EXAMINE,
	TAKE,
	DROP,
	INVENTORY,
	OPEN,
	LOOK,
	HELP,
	EMPTY
};

static const unordered_map<string, CommandType> commandMap = {
	{"GO", GO},
	{"ATTACK", ATTACK}, {"KILL", ATTACK},
	{"EXAMINE", EXAMINE},
	{"TAKE", TAKE},
	{"DROP", DROP},
	{"INVENTORY", INVENTORY}, {"I", INVENTORY},
	{"OPEN", OPEN},
	{"LOOK", LOOK}, {"L", LOOK},
	{"HELP", HELP}, {"H", HELP}
};

class Command
{
protected:
	Hero* hero;

public:
	Command(Hero* hero);
	virtual void Execute() = 0;
	virtual ~Command();

	static CommandType GetCommand(string& command)
	{
		try
		{
			return commandMap.at(command);
		}
		catch (exception&)
		{
			return EMPTY;
		}
	}
};
