#include <iostream>

#include "Game.h"

Game::Game() {
	sceneParser = new SceneParser();
	const string start = "start";
	currentScene = sceneParser->Parse(start);
	delete sceneParser;
}

void Game::Start() {
	std::cout << "Welcome to Zork!\n";
	Loop();
}

void Game::Loop() {
	
}

Game::~Game() {}