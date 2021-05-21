#include <iostream>
#include <fstream>
#include <sstream>

#include "SceneParser.h"

#include "Foe.h"
#include "Item.h"
#include "Util.h"

SceneParser::SceneParser() = default;

list<Scene*> SceneParser::Parse(const string& sceneFile)
{
	list<string> pendingScenesToLoad;
	bool loaded = find(loadedScenes.begin(), loadedScenes.end(), sceneFile) != loadedScenes.end();
	if (loaded)
	{
		return list<Scene*>();
	}

	const string PATHS = "#PATHS#";
	const string ITEMS = "#ITEMS#";
	const string FOES = "#FOES#";
	const string NONE = "NONE";

	ifstream sceneConfig;
	sceneConfig.open(sceneFile + ".scene");
	if (!sceneConfig)
	{
		string errorMessage = "Scene config file not found: " + sceneFile;
		throw exception(errorMessage.c_str());
	}

	auto scene = new Scene();
	string line;

	//read id
	getline(sceneConfig, line);
	scene->setId(line);

	//read name
	getline(sceneConfig, line);
	scene->setName(line);

	//read short description
	getline(sceneConfig, line);
	scene->setShortDescription(line);

	//read description
	getline(sceneConfig, line);
	scene->setDescription(line);

	//read dark (optional attribute)
	getline(sceneConfig, line);
	if (line.find('#') == string::npos)
	{
		scene->setDark(true);
		getline(sceneConfig, line); //read the PATHS section header
	}

	//read paths
	while (getline(sceneConfig, line))
	{
		if (line == ITEMS)
		{
			break;
		}
		auto tokens = this->Split(line);
		if (tokens.size() < PATH_CONFIG_SIZE)
		{
			throw exception("Invalid configuration for paths");
		}
		string direction = tokens.front();
		string sceneName = tokens.back();
		auto path = new Path(Path::directionFromName(direction), sceneName);
		scene->addPath(path);

		loaded = find(loadedScenes.begin(), loadedScenes.end(), sceneName) != loadedScenes.end();
		if (!loaded)
		{
			pendingScenesToLoad.push_back(sceneName);
		}
	}

	//read items
	list<Item*> sceneItems;
	multimap<string, Item*> pendingItems;
	while (getline(sceneConfig, line))
	{
		if (line == FOES)
		{
			break;
		}
		auto tokens = this->Split(line);
		if (tokens.size() < ITEM_CONFIG_SIZE)
		{
			throw exception("Invalid configuration for items");
		}

		auto item = new Item();

		string value = tokens.front();
		tokens.pop_front();
		item->setName(value);

		value = tokens.front();
		tokens.pop_front();
		item->setType(value);

		value = tokens.front();
		tokens.pop_front();
		item->setMagnitude(stoi(value));

		value = tokens.front();
		tokens.pop_front();
		if (value != NONE)
		{
			if (find(sceneItems.begin(), sceneItems.end(), value) == sceneItems.end())
			{
				//container item has not loaded, item will be added to the container later
				pendingItems.insert(make_pair(value, item));
			}
			else
			{
				//get container item
				Item* it = getItem(sceneItems, value);
				it->add(item);
			}
		}
		else
		{
			sceneItems.push_back(item);
		}
	}
	//load pending items
	if (!pendingItems.empty())
	{
		if (sceneItems.empty())
		{
			throw exception("Invalid configuration for items");
		}
		for (const auto& pi : pendingItems)
		{
			Item* it = getItem(sceneItems, pi.first);
			it->add(pi.second);
		}
		pendingItems.clear();
	}
	scene->setItems(sceneItems);

	//read foes
	while (getline(sceneConfig, line))
	{
		auto tokens = this->Split(line);
		if (tokens.size() < FOE_CONFIG_SIZE)
		{
			throw exception("Invalid configuration for foe");
		}

		string name = tokens.front();
		tokens.pop_front();

		string description = tokens.front();
		tokens.pop_front();

		string health = tokens.front();
		tokens.pop_front();

		string damage = tokens.front();
		tokens.pop_front();

		auto foe = new Foe(name, description, stoi(health), stoi(damage));

		if (!tokens.empty())
		{
			Item* item = getItem(sceneItems, tokens.front());
			tokens.pop_front();
			if (item)
			{
				foe->addItem(item);
				scene->removeItem(item);
			}
		}
		scene->addEnemy(foe);
	}

	this->loadedScenes.push_back(sceneFile);
	pendingScenesToLoad.remove(sceneFile);
	this->scenes.push_back(scene);
	if (!pendingScenesToLoad.empty())
	{
		for (const auto& pending : pendingScenesToLoad)
		{
			Parse(pending);
		}
	}
	return this->scenes;
}

list<string> SceneParser::Split(string& s) const
{
	list<string> tokens;
	stringstream stream(s);
	string token;
	while (getline(stream, token, '|'))
	{
		tokens.push_back(token);
	}
	return tokens;
}

Item* SceneParser::getItem(list<Item*> items, const string& item)
{
	return Util::filter<Item*>(items, [=](const Item* i) { return i->getName() == item; }).front();
}


SceneParser::~SceneParser()
{
	loadedScenes.clear();
	scenes.clear();
}
