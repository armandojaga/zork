#include <iostream>

#include "Game.h"

#include <sstream>

#include "Util.h"
#include "characters/Hero.h"
#include "parsers/SceneParser.h"

Game::Game()
{

	string name = "Mando";
	string desc = "Castaway";
	int health = 100;
	int attack = 1;
	hero = new Hero(name, desc, health, attack);
	sceneParser = new SceneParser();
	commandParser = new CommandParser();
	
	const string start = "start";
	list<Scene*> scenes = sceneParser->Parse(start);
	const auto currentScene = Util::find<Scene>(scenes, [&](const Scene* s) { return s->getId() == start; });
	hero->setCurrentScene(currentScene);
	
	scenes.clear();
	delete sceneParser;
}

void Game::Start()
{
	cout << "Welcome to my take on Zork!" << endl;
	cout << "You were on a cruise enjoying your vacation when a sudden storm struck and the ship sunk." << endl;
	cout<< "You washed ashore and managed to survive, finding yourself in an unknown land." << endl;
	cout << endl;
	hero->getCurrentScene()->printBrief();
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

		Command* command = commandParser->Parse(tokens, hero);
		ExecuteCommand(command);
		
		tokens.clear();
		if(hero->canEscape())
		{
			cout << endl;
			cout << "You have picked all the parts and fixed the radio" << endl;
			cout << "You called for help and the next day the help arrived, you've been saved." << endl;
			break;
		}
	}
	cout << endl;
	cout << "Thank you for playing" << endl;
}

void Game::ExecuteCommand(Command* command)
{
	command->Execute();
	cout << endl;
}

Game::~Game()
{
}
