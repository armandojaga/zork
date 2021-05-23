#include <iostream>
#include <utility>

#include "OpenCommand.h"
#include "../Util.h"
#include "../navigation/Scene.h"

using namespace std;

OpenCommand::OpenCommand(Hero* hero, string item): AbstractCommand(hero), item(std::move(item))
{
}

void OpenCommand::Execute()
{
	if (hero->getCurrentScene()->isDark() && !hero->getCurrentScene()->isIlluminated())
	{
		cout << "It's pitch black, you can't see anything to open" << endl;
		return;
	}
	const auto toOpen = Util::find<Item>(this->hero->getCurrentScene()->getItems(), [&](const Item* i)
	{
		return Util::areEqualsIgnoreCase(i->getName(), item);
	});

	if (toOpen)
	{
		hero->open(*toOpen);
	}
	else
	{
		cout << "There's no such thing as " << item << " here" << endl;
	}
}
