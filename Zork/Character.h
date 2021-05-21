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
	Scene* currentScene;

protected:
	string name;
	string description;
	int health;
	int damage;

public:
	Character(string name, string description, int health, int damage);
	virtual ~Character();
	
	string getName() const { return this->name; }
	string getDescription() const { return this->description; }
	list<Item*> getItems() const { return this->items; }
	int getDamage() const { return this->damage; }
	int getHealth() const { return this->health; }
	
	bool isAlive() const { return this->health > 0; }

	void attack(Character* enemy);
	void takeHit(int damage);
	void dropItem(Item* item);
	void dropAll();
	void setCurrentScene(Scene* scene);
	void addItem(Item* item);

	virtual void printStats() = 0;
};
