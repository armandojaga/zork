#include "EatCommand.h"
#include "../Util.h"

#include <iostream>

EatCommand::EatCommand(Hero* hero, const string& item) : Command(hero), item(item)
{
};

void EatCommand::Execute()
{
	if (!hero->hasItems())
	{
		cout << "You're don't anything to eat" << endl;
		return;
	}
	const auto toEat = Util::find<Item>(this->hero->getItems(), [&](const Item* i)
	{
		return Util::areEqualsIgnoreCase(i->getName(), item);
	});
	if (toEat && toEat->getType() == HEALING)
	{
		hero->heal(toEat->getMagnitude());
		cout << "You ate " << toEat->getName() << endl;
		hero->remove(toEat);
	}
	else
	{
		cout << "You can't eat that" << endl;
	}
}

EatCommand::~EatCommand() = default;
