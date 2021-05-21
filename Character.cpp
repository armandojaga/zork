#include "Character.h"

Character::Character(string name, string description, int health, int damage):
	name(name), description(description), health(health), damage(damage)
{
}

void Character::attack(Character* enemy)
{
}

void Character::takeHit(int damage)
{
	this->health -= damage;
}

void Character::dropItem(Item* item)
{
	this->items.remove(item);
	this->currentScene->addItem(item);
}

void Character::dropAll()
{
	for (auto item : this->items)
	{
		this->currentScene->addItem(item);
	}
	this->items.clear();
}

void Character::setCurrentScene(Scene* scene)
{
	this->currentScene = scene;
}

void Character::addItem(Item* item)
{
	this->items.push_back(item);
}

Character::~Character()
{
	this->items.clear();
}
