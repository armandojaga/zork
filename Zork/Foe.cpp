#include "Foe.h"

Foe::Foe(string name, string description, int health, int damage) : Character(name, description, health, damage)
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
