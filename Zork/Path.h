#pragma once
#include <string>
#include <unordered_map>

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

class Path
{
private:
	Direction direction;
	string scene;
public:
	Path(Direction direction, string& scene);
	~Path();

	Direction getDirection() const { return this->direction; }
	string getSceneName() const { return this->scene; }

	static Direction directionFromName(string& directionName)
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
