#include "Character.h"
#include <algorithm>

void Character::_remove(Item* item)
{
	if (item->isWeapon())
	{
		this->weapons.remove(item);
	}
	else if (item->isAmmo())
	{
		this->ammo.remove(item);
	}
	this->items.remove(item);
}

void Character::_add(Item* item)
{
	if (item->isWeapon())
	{
		this->weapons.push_back(item);
	}
	else if (item->isAmmo())
	{
		this->ammo.push_back(item);
	}
	this->items.push_back(item);
}

Character::Character(string& name, string& description, int& health, int& damage):
	name(name), description(description), health(health), damage(damage)
{
	currentScene = nullptr;
}

int Character::attack(Character& enemy)
{
	int dmg = this->getDamage();
	if(getCurrentWeapon())
	{
		dmg = getCurrentWeapon()->getMagnitude();
	}
	dmg = min(dmg, rand() % dmg + 5); //[5,dmg]
	enemy.takeHit(dmg);
	return dmg;
}

void Character::takeHit(const int& damage)
{
	this->health = max<int>(this->health - damage, 0);
}

void Character::heal(const int& health)
{
	this->health += health;
}

void Character::dropItem(Item* item)
{
	_remove(item);
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
	this->weapons.clear();
	this->ammo.clear();
}

void Character::setCurrentScene(Scene* scene)
{
	this->currentScene = scene;
}

void Character::addItem(Item* item)
{
	_add(item);
	this->items.push_back(item);
}

void Character::remove(Item* item)
{
	_remove(item);
	delete item;
}

void Character::take(Item* item)
{
	this->currentScene->removeItem(item);
	_add(item);
}

void Character::take(Item* container, Item* item)
{
	container->remove(item);
	_add(item);
}

Character::~Character()
{
	this->items.clear();
	this->weapons.clear();
	this->ammo.clear();
}
