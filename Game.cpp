#include <iostream>

#include "Game.h"

#include <sstream>

#include "Util.h"
#include "Hero.h"
#include "SceneParser.h"
#include "commands/AttackCommand.h"

Game::Game()
{
	hero = new Hero("Mando", "Castaway", 100, 1);
	sceneParser = new SceneParser();
	commandPaser = new CommandPaser();
	
	const string start = "start";
	scenes = sceneParser->Parse(start);
	const auto currentScene = Util::find<Scene>(scenes, [=](const Scene* s) { return s->getId() == start; });

	hero->setCurrentScene(currentScene);

	delete sceneParser;
}

void Game::Start()
{
	std::cout << "Welcome to Zork!\n";
	Loop();
}

void Game::Loop()
{
	string input;
	list<string> tokens;
	while(hero->isAlive())
	{
		cout << "> ";
		//get user input
		getline(cin, input);
		cout << endl;

		stringstream stream(input);
		string token;
		while (getline(stream, token, ' '))
		{
			tokens.push_back(token);
		}

		Command* command = commandPaser->Parse(tokens, hero);
		ExecuteCommand(command);
		
		tokens.clear();
	}
}

void Game::ExecuteCommand(Command* command)
{
	command->Execute();
	cout << endl;
}

Game::~Game()
{
}
