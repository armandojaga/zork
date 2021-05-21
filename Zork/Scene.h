#pragma once
#include <string>
#include <list>

#include "Character.h"
#include "Item.h"
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
	list<Path*> paths;
	list<Item*> items;
	list<Character*> enemies;

public:
	Scene();
	~Scene();

	string getId() const { return this->id; }
	string getName() const { return this->name; }
	string getShortDescription() const { return this->shortDescription; }
	string getDescription() const { return this->description; }
	bool isDark() const { return this->dark; }
	bool hasEnemies() const { return !this->enemies.empty(); }
	list<Character*> getEnemies() const { return this->enemies; }
	
	Path* getPath(Direction direction);
	bool hasPath(Direction direction);

	void setId(string id);
	void setName(string name);
	void setShortDescription(string shortDescription);
	void setDescription(string description);
	void setDark(bool isDark);

	void addPath(Path* path);
	Item* take(string& item);
	Item* take(string& container, string& item);
	list<Item*> takeAll();
	void setItems(list<Item*> items);
	void addItem(Item* item);
	void removeItem(Item* item);
	void addEnemy(Character* enemy);
	void removeEnemy(Character* enemy);

	string getBrief();

};
