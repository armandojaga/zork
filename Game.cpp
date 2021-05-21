#include <iostream>

#include "Game.h"
#include "Util.h"
#include "Hero.h"
#include "SceneParser.h"
#include "commands/AttackCommand.h"

Game::Game()
{
	sceneParser = new SceneParser();
	commandPaser = new CommandPaser();
	const string start = "start";
	scenes = sceneParser->Parse(start);
	const auto currentScene = Util::find<Scene>(scenes, [=](const Scene* s) { return s->getId() == start; });
	hero = new Hero("Mando", "Castaway", 100, 1);
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
}

void Game::ExecuteCommand(Command* command)
{
	command->Execute();
}

Game::~Game()
{
}
