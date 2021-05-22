#pragma once
#include "CommandParser.h"
#include "Hero.h"
#include "SceneParser.h"
#include "Scene.h"
#include "commands/Command.h"

using namespace std;

class Game
{
private:
	SceneParser* sceneParser;
	CommandPaser* commandPaser;
	Hero* hero;
	void Loop();
	void ExecuteCommand(Command* command);

public:
	Game();
	~Game();
	void Start();
};
