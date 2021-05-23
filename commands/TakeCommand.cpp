#include "TakeCommand.h"
#include "../Util.h"

#include <iostream>
#include <utility>

using namespace std;

TakeCommand::TakeCommand(Hero* hero, string item) : AbstractCommand(hero), item(std::move(item))
{
};

void TakeCommand::Execute()
{
	if (hero->getCurrentScene()->isDark() && !hero->getCurrentScene()->isIlluminated())
	{
		cout << "It's pitch black, you can't take anything" << endl;
		return;
	}
	if (!hero->getCurrentScene()->hasItems())
	{
		cout << "There's nothing you can take" << endl;
		return;
	}

	const function<void(Item& i)> print([&](Item& i)
	{
		cout << "You took " << i.getName() << endl;
	});

	const function<bool(bool&)> tryTake([&](bool& single)
	{
		bool took = false;
		for (auto sceneItem : hero->getCurrentScene()->getItems())
		{
			if (took && single)
			{
				break;
			}
			if (sceneItem->IsContainer() && Util::areEqualsIgnoreCase(item, sceneItem->getName()))
			{
				cout << "You can't take that" << endl;
				took = true; //this is to skip the next validation
				break;
			}
			if (sceneItem->IsContainer() && sceneItem->getType() != OPEN_BOX)
			{
				continue;
			}
			if (sceneItem->getType() == OPEN_BOX)
			{
				for (auto containerItem : sceneItem->getItems())
				{
					if (!single || Util::areEqualsIgnoreCase(item, containerItem->getName()))
					{
						hero->take(sceneItem, containerItem);
						print(*containerItem);
						took = true;
					}
				}
			}
			else
			{
				if (!single || Util::areEqualsIgnoreCase(item, sceneItem->getName()))
				{
					hero->take(sceneItem);
					print(*sceneItem);
					took = true;
				}
			}
		}
		return took;
	});

	if (Util::areEqualsIgnoreCase(item, "all"))
	{
		bool single = false;
		if (!tryTake(single))
		{
			cout << "There is nothing you can take" << endl;
		}
	}
	else
	{
		bool single = true;
		if (!tryTake(single))
		{
			cout << "You can't take something that it's not there" << endl;
		}
	}
}
