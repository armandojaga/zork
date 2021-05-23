#ifndef ZORK_COMMANDS_ABSTRACT_COMMAND_H
#define ZORK_COMMANDS_ABSTRACT_COMMAND_H

#include <string>
#include <unordered_map>

#include "../characters/Hero.h"

enum eCommandType
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

static const std::unordered_map<std::string, eCommandType> commandMap = {
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

class AbstractCommand
{
protected:
	Hero* hero;

public:
	AbstractCommand(Hero* hero);
	AbstractCommand(const AbstractCommand&) = delete;
	AbstractCommand& operator =(const AbstractCommand&) = delete;
	AbstractCommand(AbstractCommand&&) = delete;
	AbstractCommand& operator=(AbstractCommand&&) = delete;
	virtual void Execute() = 0;
	virtual ~AbstractCommand() = default;

	static eCommandType GetCommand(std::string& command)
	{
		try
		{
			return commandMap.at(command);
		}
		catch (std::exception&)
		{
			return EMPTY;
		}
	}
};

#endif  //ZORK_COMMANDS_ABSTRACT_COMMAND_H
