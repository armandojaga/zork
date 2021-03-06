#include "DropCommand.h"
#include "../Util.h"

#include <iostream>
#include <utility>

using namespace std;

DropCommand::DropCommand(Hero* hero, string item) : AbstractCommand(hero), item(std::move(item))
{
};

void DropCommand::Execute()
{
	if (!hero->hasItems())
	{
		cout << "You're empty handed" << endl;
		return;
	}
	if (Util::areEqualsIgnoreCase(item, "all"))
	{
		hero->dropAll();
		cout << "You dropped all your items" << endl;
	}
	else
	{
		const auto toDrop = Util::find<Item>(this->hero->getItems(), [&](const Item* i)
		{
			return Util::areEqualsIgnoreCase(i->getName(), item);
		});
		if (toDrop)
		{
			hero->dropItem(toDrop);
			cout << "You dropped " << toDrop->getName() << endl;
		}
		else
		{
			cout << "You can't drop something you don't have" << endl;
		}
	}
}
