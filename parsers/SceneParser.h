#ifndef ZORK_PARSERS_SCENE_PARSER_H
#define ZORK_PARSERS_SCENE_PARSER_H

#include <string>
#include "../navigation/Scene.h"
#include <list>

class SceneParser
{
	static const int PATH_CONFIG_SIZE = 2;
	static const int ITEM_CONFIG_SIZE = 4;
	static const int FOE_CONFIG_SIZE = 4;
private:
	struct PendingPath
	{
		std::string targetScene;
		Path* path;
		std::string scene;
		bool loaded;

		PendingPath(const std::string& scene, Path* p, std::string& targetScene)
		{
			this->loaded = false;
			this->scene = scene;
			this->path = p;
			this->targetScene = targetScene;
		}
	};

	std::list<Scene*> scenes;
	std::list<std::string> loadedScenes;
	std::list<std::string> Split(std::string& s) const;
	std::vector<PendingPath> pendingPaths;
	Item* getItem(const std::list<Item*>& items, const std::string& item);

public:
	SceneParser() = default;
	SceneParser(const SceneParser&) = delete;
	SceneParser& operator =(const SceneParser&) = delete;
	SceneParser(SceneParser&&) = delete;
	SceneParser& operator=(SceneParser&&) = delete;

	~SceneParser();

	std::list<Scene*> Parse(const std::string& sceneFile);
};

#endif  //ZORK_PARSERS_SCENE_PARSER_H
