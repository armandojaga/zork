#pragma once
#include <string>
#include "../navigation/Scene.h"
#include <list>
#include <map>

using namespace std;

class SceneParser
{
	static const int PATH_CONFIG_SIZE = 2;
	static const int ITEM_CONFIG_SIZE = 4;
	static const int FOE_CONFIG_SIZE = 4;
private:
	struct PendingPath
	{
		string targetScene;
		Path* path;
		string scene;
		bool loaded;

		PendingPath(const string& scene, Path* p, string& targetScene)
		{
			this->loaded = false;
			this->scene = scene;
			this->path = p;
			this->targetScene = targetScene;
		}
	};

	list<Scene*> scenes;
	list<string> loadedScenes;
	list<string> Split(string& s) const;
	vector<PendingPath> pendingPaths;
	Item* getItem(list<Item*> items, const string& item);
public:
	SceneParser();
	~SceneParser();
	list<Scene*> Parse(const string& sceneFile);
};
