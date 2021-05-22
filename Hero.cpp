#include "Hero.h"

#include "Util.h"

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
	if (hasItems()) {
		cout << " " << "Items" << endl;
		for (auto item : this->getItems())
		{
			cout << " " << "- " << item->getName() << endl;
		}
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
		bool isDark = this->getCurrentScene()->isDark();
		if(isDark && !this->getItems().empty())
		{
			auto l = Util::filter<Item*>(this->getItems(), [](const Item* i) { return i->getType() == LIGHT; });
			if(!l.empty())
			{
				this->getCurrentScene()->setIlluminated(true);
			}
		}
		destination->getScene()->printBrief();
	}else
	{
		cout << "you can't go there" << endl;
	}
}

void Hero::open(Item& toOpen)
{
	const function<void(Item& i)> printItemInfo([&](Item& i)
	{
		if (i.hasItems())
		{
			cout << i.getName() << " contains: " << endl;
			for (auto it : i.getItems())
			{
				cout << "- " << it->getName() << endl;
			}
		}
		else
		{
			cout << i.getName() << " is empty" << endl;
		}
	});
	
	if (toOpen.IsContainer())
	{
		if (toOpen.IsLocked())
		{
			const auto key = Util::find<Item>(this->getItems(), [](const Item* i)
			{
				return i->getType() == KEY;
			});
			if (key)
			{
				cout << "You used the key to open " << toOpen.getName() << endl;
				ItemType newType = OPEN_BOX;
				toOpen.setType(newType);
				this->remove(key);
				printItemInfo(toOpen);
			}
			else
			{
				cout << "You need a key to open it" << endl;
			}
		}
		else if (toOpen.getType() == BOX)
		{
			cout << "You opened " << toOpen.getName() << endl;
			printItemInfo(toOpen);
		}
		else
		{
			cout << "It's already open" << endl;
			printItemInfo(toOpen);
		}
	}
	else
	{
		cout << "You can't open that" << endl;
	}
}
