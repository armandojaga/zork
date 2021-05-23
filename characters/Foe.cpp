#include <iostream>

#include "Foe.h"

using namespace std;

Foe::Foe(string& name, string& description, int& health, int& damage) : Character(name, description, health, damage)
{
}

void Foe::printStats()
{
}

Item* Foe::getCurrentWeapon()
{
	if (this->getWeapons().empty())
	{
		return nullptr;
	}
	return this->getWeapons().front();
}

void Foe::dropDead()
{
	cout << endl;
	cout << getName() << " died";
	if (hasItems())
	{
		cout << " and dropped:" << endl;
		for (auto item : this->getItems())
		{
			cout << "+ " << item->getName() << endl;
			this->dropItem(item);
		}
	}
	cout << endl;
}
