#include "Foe.h"

Foe::Foe(string& name, string& description, int& health, int& damage) : Character(name, description, health, damage)
{
}

Foe::~Foe()
{
}

void Foe::printStats()
{
	cout << name << "'s stats" << endl;
	cout << " Health: " << health << endl;
	cout << " Attack: " << damage << endl;
	cout << " Items: " << endl;
	for (auto item : this->getItems())
	{
		cout << " - " << item->getName() << endl;
	}
	cout << endl;
}

Item* Foe::getCurrentWeapon()
{
	if(this->getWeapons().empty())
	{
		return nullptr;
	}
	return this->getWeapons().front();
}

void Foe::dropDead()
{
	cout << endl;
	cout << getName() << " died";
	if(hasItems())
	{
		cout << " and dropped:" << endl;
		for (auto item : this->getItems())
		{
			cout << "+ "<< item->getName() << endl;
			this->dropItem(item);
		}
	}
	cout << endl;
}
