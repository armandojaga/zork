#include <iostream>
#include <fstream>
#include <sstream>

#include "SceneParser.h"

SceneParser::SceneParser() = default;

Scene* SceneParser::Parse(const string& sceneFile)
{
	const string PATHS = "#PATHS#";
	const string ITEMS = "#ITEMS#";
	const string FOES = "#FOES#";
	const int PATH_CONFIG_SIZE = 2;
	const int ITEM_CONFIG_SIZE = 4;
	const int FOE_CONFIG_SIZE = 4;

	auto scene = new Scene();
	cout << "parsing" << endl;
	ifstream toRead;
	toRead.open(sceneFile + ".scene");
	if (!toRead)
	{
		cout << "File " << sceneFile << " not found" << endl;
	}
	else
	{
		cout << "reading file " << sceneFile << endl;
		string line;

		//read id
		getline(toRead, line);
		scene->setId(line);

		//read name
		getline(toRead, line);
		scene->setName(line);

		//read short description
		getline(toRead, line);
		scene->setShortDescription(line);

		//read description
		getline(toRead, line);
		scene->setDescription(line);

		//read dark (optional attribute)
		getline(toRead, line);
		if (line.find('#') == string::npos)
		{
			scene->setDark(true);
			getline(toRead, line); //read the PATHS section header
		}

		//read paths
		while (getline(toRead, line))
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
			string path = tokens.back();
			this->pathsToLoad.insert(make_pair(direction, path));
		}

		//read items
		while (getline(toRead, line))
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
		}

		//read foes
		while (getline(toRead, line))
		{
			auto tokens = this->Split(line);
			if (tokens.size() < FOE_CONFIG_SIZE)
			{
				throw exception("Invalid configuration for foe");
			}
		}
	}
	this->loadedScenes.push_back(sceneFile);
	return scene;
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

SceneParser::~SceneParser()
{
	loadedScenes.clear();
}
