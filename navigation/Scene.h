#ifndef ZORK_NAVIGATION_SCENE_H
#define ZORK_NAVIGATION_SCENE_H

#include <string>
#include <list>

#include "../characters/Character.h"
#include "../Item.h"
#include "Path.h"

class Scene
{
private:
	std::string id;
	std::string name;
	std::string shortDescription;
	std::string description;
	bool dark;
	bool isBeingIlluminated;
	std::list<Path*> paths;
	std::list<Item*> items;
	std::list<Character*> enemies;
	bool visited;

public:
	Scene(bool);
	Scene(const Scene&) = delete;
	Scene& operator =(const Scene&) = delete;
	Scene(Scene&&) = delete;
	Scene& operator=(Scene&&) = delete;

	~Scene();

	std::string getId() const { return this->id; }
	std::string getName() const { return this->name; }
	std::string getShortDescription() const { return this->shortDescription; }
	std::string getDescription() const { return this->description; }

	bool hasEnemies() const { return !this->enemies.empty(); }
	std::list<Character*> getEnemies() const { return this->enemies; }
	bool hasItems() const { return !this->items.empty(); }
	std::list<Item*> getItems() const { return this->items; }

	Path* getPath(eDirection direction);
	bool hasPath(eDirection direction);

	void setId(std::string id);
	void setName(std::string name);
	void setShortDescription(std::string shortDescription);
	void setDescription(std::string description);

	bool hasVisited() const { return this->visited; }
	bool isIlluminated() const { return this->isBeingIlluminated; }
	bool isDark() const { return this->dark; }

	void setIlluminated(bool);
	void setVisited(bool);

	void addPath(Path* path);
	void setItems(std::list<Item*>& items);
	void addItem(Item* item);
	void removeItem(Item* item);
	void addEnemy(Character* enemy);
	void removeEnemy(Character* enemy);

	void printBrief();
};

#endif  //ZORK_NAVIGATION_SCENE_H
