#pragma once
#include <iostream>
#include <string>

#include "Item.h"
#include "Scene.h"

class Scene;

using namespace std;

class Character
{
private:
	list<Item*> items;
	list<Item*> weapons;
	list<Item*> ammo;
	list<Item*> storyItems;
	Scene* currentScene;
	void _remove(Item*);
	void _add(Item*);

protected:
	string name;
	string description;
	int health;
	int damage;

public:
	Character(string& name, string& description, int& health, int& damage);
	virtual ~Character();

	string getName() const { return this->name; }
	string getDescription() const { return this->description; }
	list<Item*> getItems() const { return this->items; }
	int getDamage() const { return this->damage; }
	int getHealth() const { return this->health; }
	Scene* getCurrentScene() const { return this->currentScene; }
	bool hasItems() const { return !this->items.empty(); }
	list<Item*> getWeapons() const { return this->weapons; }
	list<Item*> getAmmo() const { return this->ammo; }
	list<Item*> getStoryItems() const { return this->storyItems; }

	bool isAlive() const { return this->health > 0; }

	int attack(Character& enemy);
	void takeHit(const int& damage);
	void heal(const int& health);
	void dropItem(Item* item);
	void dropAll();
	void setCurrentScene(Scene* scene);
	void addItem(Item* item);
	void remove(Item* item);
	void take(Item* item);
	void take(Item* container, Item* item);

	virtual void printStats() = 0;
	virtual Item* getCurrentWeapon() = 0;
	virtual void dropDead() = 0;
};
