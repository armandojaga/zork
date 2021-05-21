#include "Hero.h"

Hero::Hero(string name, string description, int health, int damage) : Character(name, description, health, damage)
{
}

Hero::~Hero()
{
}

void Hero::printStats()
{
	const string delimiter = "======================";
	cout << delimiter << endl;
	cout << "     Player stats" << endl;
	cout << "----------------------" << endl;
	cout << "        " << name << endl;
	cout << "----------------------" << endl;
	cout << " " << "Health: " << health << endl;
	cout << " " << "Items" << endl;
	for (auto item : this->getItems())
	{
		cout << " " << "- " << item->getName() << endl;
	}
	cout << delimiter << endl;
	cout << endl;
}
