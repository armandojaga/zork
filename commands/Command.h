#pragma once
#include <string>
#include <unordered_map>

#include "../Hero.h"

using namespace std;

enum CommandType
{
	GO,
	ATTACK,
	TAKE,
	DROP,
	INVENTORY,
	OPEN,
	LOOK,
	HELP,
	EAT,
	EMPTY
};

static const unordered_map<string, CommandType> commandMap = {
	{"GO", GO},
	{"ATTACK", ATTACK}, {"KILL", ATTACK},
	{"TAKE", TAKE},
	{"DROP", DROP},
	{"INVENTORY", INVENTORY}, {"I", INVENTORY},
	{"OPEN", OPEN},
	{"LOOK", LOOK}, {"L", LOOK},
	{"HELP", HELP}, {"H", HELP},
	{"EAT", EAT}
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
