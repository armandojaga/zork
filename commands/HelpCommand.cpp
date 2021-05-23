#include <iostream>
#include <fstream>

#include "HelpCommand.h"

using namespace std;

HelpCommand::HelpCommand() : AbstractCommand(nullptr)
{
}

HelpCommand::HelpCommand(Hero* hero): AbstractCommand(hero)
{
}

void HelpCommand::Execute()
{
	ifstream help("help.txt");
	string line;
	while (getline(help, line))
	{
		cout << line << endl;
	}
}
