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
	
	if (toOpen)
	{
		if (toOpen->IsContainer())
		{
			if (toOpen->IsLocked())
			{
				const auto key = Util::find<Item>(this->hero->getItems(), [](const Item* i)
				{
					return i->getType() == KEY;
				});
				if (key)
				{
					cout << "You used the key to open " << item << endl;
					ItemType newType = OPEN_BOX;
					toOpen->setType(newType);
					hero->getItems().remove(key);
					printItemInfo(*toOpen);
				}
				else
				{
					cout << "You need a key to open it" << endl;
				}
			}
			else if (toOpen->getType() == BOX)
			{
				cout << "You opened " << item << endl;
				printItemInfo(*toOpen);
			}
			else
			{
				cout << "It's already open" << endl;
				printItemInfo(*toOpen);
			}
		}
		else
		{
			cout << "You can't open that" << endl;
		}
	}
	else
	{
		cout << "There's no such thing as " << item << " here" << endl;
	}
}
