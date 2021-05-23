#include "AttackCommand.h"
#include "../Util.h"

#include <iostream>

class Foe;

AttackCommand::AttackCommand(Hero* hero, const vector<string>& params) : Command(hero), params(params)
{
};

void AttackCommand::Execute()
{
	if (hero->getCurrentScene()->getEnemies().empty())
	{
		cout << "There's no enemy to attack here" << endl;
		return;
	}
	if (params.size() > 3)
	{
		cout << "You can't attack like that" << endl;
		return;
	}
	if (params.size() == 2 || (params.size() > 2 && !Util::areEqualsIgnoreCase(params[1], "with")))
	{
		cout << "What do you want to attack with?" << endl;
		return;
	}
	const auto foe = Util::find<Character>(hero->getCurrentScene()->getEnemies(), [&](const Character* c)
	{
		return Util::areEqualsIgnoreCase(c->getName(), params[0]);
	});
	if (!foe)
	{
		cout << "No enemy like that here, which enemy you want to attack?" << endl;
		return;
	}
	Item* weapon = nullptr;
	if (hero->getWeapons().empty())
	{
		cout << "You have no weapons";
	}
	else
	{
		if (params.size() == 3)
		{
			weapon = Util::find<Item>(this->hero->getItems(),
			                          [&](const Item* i)
			                          {
				                          return Util::areEqualsIgnoreCase(i->getName(), params[2]);
			                          });
			if (!weapon)
			{
				cout << "You don't have that";
			}
			else if (!weapon->isWeapon())
			{
				cout << "You can't attack with that";
				weapon = nullptr;
			}
			else if (weapon->getType() == RANGE_WEAPON && hero->getAmmo().empty())
			{
				cout << "You have no ammo";
				weapon = nullptr;
			}
		}
		else if (params.size() > 1)
		{
			cout << "What do you want to attack with?" << endl;
			return;
		}
		else
		{
			cout << "You're are determined";
		}
	}
	if (!weapon)
	{
		cout << ", you're attacking with your bare hands" << endl;
	}
	hero->attack(*foe, weapon);
}

AttackCommand::~AttackCommand() = default;
