#pragma once
#include "Hero.h"
#include "SceneParser.h"
#include "Scene.h"

using namespace std;

class Game {
private:
	SceneParser* sceneParser;
	Hero* hero;
	list<Scene*> scenes;
	void Loop();

public:
	Game();
	~Game();
	void Start();
};
