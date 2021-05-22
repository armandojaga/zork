#include <iostream>

#include "Game.h"

#include <sstream>

#include "Util.h"
#include "Hero.h"
#include "SceneParser.h"

Game::Game()
{
	string name = "Mando";
	int health = 100;
	int attack = 1;
	hero = new Hero(name, name, health, attack);
	sceneParser = new SceneParser();
	commandPaser = new CommandPaser();
	
	const string start = "start";
	list<Scene*> scenes = sceneParser->Parse(start);
	const auto currentScene = Util::find<Scene>(scenes, [=](const Scene* s) { return s->getId() == start; });

	hero->setCurrentScene(currentScene);

	scenes.clear();
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
	vector<string> tokens;
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
