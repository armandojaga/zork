#pragma once
#include <string>
#include <unordered_map>

class Scene;

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
	DOWN,
	WRONG
};

static const unordered_map<string, Direction> directionMap = {
	{"NORTH", NORTH}, {"N", NORTH},
	{"SOUTH", SOUTH}, {"S", SOUTH},
	{"EAST", EAST}, {"E", EAST},
	{"WEST", WEST}, {"W", WEST},
	{"SE", SE}, {"SOUTHEAST", SE},
	{"SW", SW}, {"SOUTHWEST", SW},
	{"NE", NE}, {"NORTHEAST", NE},
	{"NW", NW}, {"NORTHWEST", NW},
	{"UP", UP}, {"U", UP},
	{"DOWN", DOWN}, {"D", DOWN}
};

static const unordered_map<Direction, string> directionNameMap = {
	{NORTH, "north"},
	{SOUTH, "south"},
	{EAST, "east"},
	{WEST, "west"},
	{SE, "southeast"},
	{SW, "southwest"},
	{NE, "northeast"},
	{NW, "northwest"}
};

class Path
{
private:
	Direction direction;
	Scene* scene;
public:
	Path(Direction direction);
	~Path();

	Direction getDirection() const { return this->direction; }
	Scene* getScene() const { return this->scene; }
	void setScene(Scene*);

	static Direction DirectionFromName(string& directionName)
	{
		try
		{
			return directionMap.at(directionName);
		}
		catch (exception&)
		{
			return WRONG;
		}
	}
};
