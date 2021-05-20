#pragma once
#include <string>
#include <list>
#include <map>

#include "Item.h"

using namespace std;

enum Direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	SE,
	SW,
	NE,
	NW,
	UP,
	DOWN
};

class Scene
{
private:
	string id;
	string name;
	string shortDescription;
	string description;
	bool dark;
	map<Direction, Scene*> paths;
	list<Item*> items;
	

public:
	Scene();
	~Scene();

	string getId() const { return this->id; }
	string getName() const { return this->name; }
	string getShortDescription() const { return this->shortDescription; }
	string getDescription() const { return this->description; }
	bool isDark() const { return this->dark; }

	Scene* getPath(Direction direction);
	bool hasPath(Direction direction);

	void setId(string id);
	void setName(string name);
	void setShortDescription(string shortDescription);
	void setDescription(string description);
	void setDark(bool isDark);

	void addPath(Direction direction, Scene* scene);
	Item* take(string& item);
	Item* take(string& container, string& item);
	list<Item*> takeAll();
	void setItems(list<Item*> items);
};
