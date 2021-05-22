#include "Hero.h"

Hero::Hero(string& name, string& description, int& health, int& damage) : Character(name, description, health, damage)
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

void Hero::go(Direction& direction)
{
	bool canGo = this->getCurrentScene()->hasPath(direction);
	if(canGo)
	{
		Path * destination = this->getCurrentScene()->getPath(direction);
		this->setCurrentScene(destination->getScene());
		destination->getScene()->printBrief();
	}else
	{
		cout << "you can't go there" << endl;
	}
}
