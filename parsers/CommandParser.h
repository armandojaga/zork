#ifndef ZORK_PARSERS_COMMAND_PARSER_H
#define ZORK_PARSERS_COMMAND_PARSER_H

#include "../commands/AbstractCommand.h"

class CommandParser
{
private:
	void ToUpper(std::string&) const;
public:
	CommandParser();
	CommandParser(const CommandParser&) = delete;
	CommandParser& operator =(const CommandParser&) = delete;
	CommandParser(CommandParser&&) = delete;
	CommandParser& operator=(CommandParser&&) = delete;

	~CommandParser() = default;

	AbstractCommand* Parse(std::vector<std::string>& args, Hero*) const;
};

#endif  //ZORK_PARSERS_COMMAND_PARSER_H
