#ifndef ZORK_NAVIGATION_PATH_H
#define ZORK_NAVIGATION_PATH_H

#include <string>
#include <unordered_map>
#include "../navigation/Scene.h"

enum eDirection
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

static const std::unordered_map<std::string, eDirection> directionMap = {
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

static const std::unordered_map<eDirection, std::string> directionNameMap = {
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
	eDirection direction;
	Scene* scene;
public:
	Path(eDirection direction);
	Path(const Path&) = delete;
	Path& operator =(const Path&) = delete;
	Path(Path&&) = delete;
	Path& operator=(Path&&) = delete;

	~Path() = default;

	eDirection getDirection() const { return this->direction; }
	Scene* getScene() const { return this->scene; }
	void setScene(Scene*);

	static eDirection DirectionFromName(std::string& directionName)
	{
		try
		{
			return directionMap.at(directionName);
		}
		catch (std::exception&)
		{
			return WRONG;
		}
	}
};

#endif  //ZORK_NAVIGATION_PATH_H
