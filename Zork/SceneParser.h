#pragma once
#include <string>
#include "Scene.h"
#include <list>
#include <map>

using namespace std;

class SceneParser
{
private:
	list<string> loadedScenes;
	map<string, string> pathsToLoad;
	list<string> Split(string &s) const;
public:
	SceneParser();
	~SceneParser();
	Scene* Parse(const string& sceneFile);
};

