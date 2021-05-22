#include "OpenCommand.h"
#include "../Util.h"
#include "../Scene.h"

OpenCommand::OpenCommand(Hero* hero, const string& item): Command(hero), item(item)
{
}

OpenCommand::~OpenCommand()
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
