#pragma once
#include <string>
#include "Scene.h"
#include <list>
#include <map>

using namespace std;

class SceneParser
{
	static const int PATH_CONFIG_SIZE = 2;
	static const int ITEM_CONFIG_SIZE = 4;
	static const int FOE_CONFIG_SIZE = 4;
private:
	list<Scene*> scenes;
	list<string> loadedScenes;
	list<string> Split(string& s) const;
	Item* getItem(list<Item*> items, const string& item);
public:
	SceneParser();
	~SceneParser();
	list<Scene*> Parse(const string& sceneFile);
};
