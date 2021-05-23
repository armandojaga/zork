#ifndef ZORK_CHARACTERS_CHARACTER_H
#define ZORK_CHARACTERS_CHARACTER_H

#include <string>

#include "../Item.h"
#include "../navigation/Scene.h"

class Scene;

class Character
{
private:
	std::list<Item*> items;
	std::list<Item*> weapons;
	std::list<Item*> ammo;
	std::list<Item*> storyItems;
	Scene* currentScene;
	void _remove(Item*);
	void _add(Item*);

protected:
	std::string name;
	std::string description;
	int health;
	int damage;

public:
	Character(std::string& name, std::string& description, int& health, int& damage);
	Character(const Character&) = delete;
	Character& operator =(const Character&) = delete;
	Character(Character&&) = delete;
	Character& operator=(Character&&) = delete;

	virtual ~Character();

	std::string getName() const { return this->name; }
	std::string getDescription() const { return this->description; }
	std::list<Item*> getItems() const { return this->items; }
	int getDamage() const { return this->damage; }
	int getHealth() const { return this->health; }
	Scene* getCurrentScene() const { return this->currentScene; }
	bool hasItems() const { return !this->items.empty(); }
	std::list<Item*> getWeapons() const { return this->weapons; }
	std::list<Item*> getAmmo() const { return this->ammo; }
	std::list<Item*> getStoryItems() const { return this->storyItems; }

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

#endif  //ZORK_CHARACTERS_CHARACTER_H
