#ifndef ZORK_COMMANDS_OPEN_COMMAND_H
#define ZORK_COMMANDS_OPEN_COMMAND_H

#include "AbstractCommand.h"

class Hero;

class OpenCommand : public AbstractCommand
{
private:
	const std::string item;
public:
	OpenCommand(Hero*, std::string item);
	OpenCommand(const OpenCommand&) = delete;
	OpenCommand& operator =(const OpenCommand&) = delete;
	OpenCommand(OpenCommand&&) = delete;
	OpenCommand& operator=(OpenCommand&&) = delete;

	~OpenCommand() override = default;

	void Execute() override;
};

#endif  //ZORK_COMMANDS_OPEN_COMMAND_H
