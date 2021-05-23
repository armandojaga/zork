#pragma once
#include <string>
#include <list>

#include "../characters/Character.h"
#include "../Item.h"
#include "Path.h"

class Character;

using namespace std;

class Scene
{
private:
	string id;
	string name;
	string shortDescription;
	string description;
	bool dark;
	bool isBeingIlluminated;
	list<Path*> paths;
	list<Item*> items;
	list<Character*> enemies;
	bool visited;

public:
	Scene(bool);
	~Scene();

	string getId() const { return this->id; }
	string getName() const { return this->name; }
	string getShortDescription() const { return this->shortDescription; }
	string getDescription() const { return this->description; }
	
	bool hasEnemies() const { return !this->enemies.empty(); }
	list<Character*> getEnemies() const { return this->enemies; }
	bool hasItems() const { return !this->items.empty(); }
	list<Item*> getItems() const { return this->items; }

	Path* getPath(Direction direction);
	bool hasPath(Direction direction);

	void setId(string id);
	void setName(string name);
	void setShortDescription(string shortDescription);
	void setDescription(string description);

	bool hasVisited() const { return this->visited; }
	bool isIlluminated() const { return this->isBeingIlluminated; }
	bool isDark() const { return this->dark; }
	
	void setIlluminated(bool);
	void setVisited(bool);

	void addPath(Path* path);
	void setItems(list<Item*> items);
	void addItem(Item* item);
	void removeItem(Item* item);
	void addEnemy(Character* enemy);
	void removeEnemy(Character* enemy);

	void printBrief();
};
