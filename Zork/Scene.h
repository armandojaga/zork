#pragma once
#include <string>
#include <list>
#include <map>

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

class Scene {
private:
	string id;
	string name;
	string shortDescription;
	string description;
	bool isDark;
	map<Direction, Scene*> paths;

public:
	Scene();
	~Scene();

	void setId(string id);
	void setName(string name);
	void setShortDescription(string shortDescription);
	void setDescription(string description);
	void setDark(bool isDark);
	
	void addPath(Direction direction, Scene* scene);
};