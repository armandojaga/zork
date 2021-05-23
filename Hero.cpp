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
		this->getCurrentScene()->setIlluminated(false);
		Path * destination = this->getCurrentScene()->getPath(direction);
		this->setCurrentScene(destination->getScene());
		bool isDark = this->getCurrentScene()->isDark();
		auto sceneLight = Util::find<Item>(this->getCurrentScene()->getItems(), [](const Item* i) { return i->getType() == LIGHT; });
		if(isDark && !this->getItems().empty() || sceneLight)
		{
			if (!sceneLight) {
				auto heroLight = Util::find<Item>(this->getItems(), [](const Item* i) { return i->getType() == LIGHT; });

				if (heroLight)
				{
					this->getCurrentScene()->setIlluminated(true);
				}
			} else
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

Item* Hero::getCurrentWeapon()
{
	return nullptr;
}

void Hero::attack(Character& enemy, Item* weapon)
{
	cout << "You attacked " << enemy.getName();
	if (rand() % 100 < 90) {//90% change of attacking
		int dmg = this->getDamage();
		if(weapon)
		{
			if(weapon->getType() == RANGE_WEAPON)
			{
				Item* ammo = this->getAmmo().front();
				dmg = ammo->getMagnitude();
				this->remove(ammo);
			}
			else
			{
				dmg = weapon->getMagnitude();
			}
		}
		enemy.takeHit(dmg);
		cout << " and caused " << dmg << " of damage [" << enemy.getName() << "'s health: "<< enemy.getHealth() << "]" << endl;
	}else
	{
		cout << ", but missed" << endl;
	}
	if (enemy.isAlive()) {
		cout << enemy.getName() << " attacked you back";
		if(rand() % 100 < 80)//80% change of attacking
		{
			const int dmg = enemy.attack(*this);
			cout <<" and caused " << dmg << " of damage" << endl;
		}else
		{
			cout << " , but missed" << endl;
		}
	} else
	{
		enemy.dropDead();
	}
	if(!isAlive())
	{
		dropDead();
	}else if(this->getHealth() <=15)
	{
		cout << "You're badly hurt" << endl;
	}
}

void Hero::dropDead()
{
	cout << endl;
	cout << "You died, this is the end of your adventure in this mysterious world" << endl;
}
