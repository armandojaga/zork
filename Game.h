#pragma once
#include "parsers//CommandParser.h"
#include "characters/Hero.h"
#include "parsers/SceneParser.h"
#include "navigation/Scene.h"
#include "commands/Command.h"

using namespace std;

class Game
{
private:
	SceneParser* sceneParser;
	CommandParser* commandParser;
	Hero* hero;
	void Loop();
	void ExecuteCommand(Command* command);

public:
	Game();
	~Game();
	void Start();
};
