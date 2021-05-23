#include "HelpCommand.h"

#include <fstream>

HelpCommand::HelpCommand() : Command(nullptr)
{
}

HelpCommand::HelpCommand(Hero* hero): Command(hero)
{
}

HelpCommand::~HelpCommand()
{
}

void HelpCommand::Execute()
{
	ifstream help("help.txt");
	string line;
	while(getline(help,line))
	{
		cout << line << endl;
	}
}
