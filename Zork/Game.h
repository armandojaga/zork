#pragma once
#include "SceneParser.h"
#include "Scene.h"

using namespace std;

class Game {
private:
	Scene* currentScene;
	SceneParser* sceneParser;
	void Loop();

public:
	Game();
	~Game();
	void Start();
};
