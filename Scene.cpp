#include "Scene.h"

#include "Util.h"

Scene::Scene(bool isDark)
{
	this->dark = isDark;
	isBeingIlluminated = false;
}

void Scene::addPath(Path* path)
{
	this->paths.push_back(path);
}

Path* Scene::getPath(Direction direction)
{
	return Util::find<Path>(this->paths, [&](const Path* p) { return p->getDirection() == direction; });
}

bool Scene::hasPath(Direction direction)
{
	return getPath(direction);
}

void Scene::setId(const string id)
{
	this->id = id;
}

void Scene::setName(const string name)
{
	this->name = name;
}

void Scene::setShortDescription(const string shortDescription)
{
	this->shortDescription = shortDescription;
}

void Scene::setDescription(const string description)
{
	this->description = description;
}

void Scene::setIlluminated(bool isBeingIlluminated)
{
	this->isBeingIlluminated = isBeingIlluminated;
}


bool Scene::isIlluminated() const
{
	return this->isBeingIlluminated;
}

void Scene::setItems(list<Item*> items)
{
	this->items = items;
}

void Scene::addItem(Item* item)
{
	this->items.push_back(item);
}

void Scene::removeItem(Item* item)
{
	this->items.remove(item);
}

void Scene::addEnemy(Character* enemy)
{
	enemy->setCurrentScene(this);
	this->enemies.push_back(enemy);
}

void Scene::removeEnemy(Character* enemy)
{
	this->enemies.remove(enemy);
}

void Scene::printBrief()
{
	const function<void(Item& i)> printItemInfo([&](Item& i)
	{
		if (i.getType() == OPEN_BOX) {
			if (i.hasItems())
			{
				cout << ", it contains: " << endl;
				for (auto it : i.getItems())
				{
					cout << "- " << it->getName() << endl;
				}
			}
			else
			{
				cout << ", but is empty" << endl;
			}
		}
		cout << endl;
	});
	
	cout << name << endl;
	cout << description << endl;
	for (auto path : paths)
	{
		if (path->getDirection() != UP && path->getDirection() != DOWN)
		{
			cout << "There is a path leading to " << path->getScene()->getShortDescription() << " to the " <<
				directionNameMap.at(path->getDirection()) << " of here" << endl;
		}
	}
	if (isDark() && !isIlluminated())
	{
		cout << "It's pitch black!" << endl;
		if (hasEnemies())
		{
			cout << "You hear a dangerous sound, it's better to get some light" << endl;
		}
	}
	else
	{
		
		for (auto item : items)
		{
			cout << "A " << item->getName() << " is here";
			printItemInfo(*item);
		}
		for (auto enemy : enemies)
		{
			cout << enemy->getName() << endl;
		}
	}
	cout << endl;
}

Item* Scene::take(string& item)
{if (isDark() && !isIlluminated())
	{
		cout << "It's dark, you can't see anything" << endl;
		return nullptr;
	}
	if (!hasItems())
	{
		cout << "There's nothing here" << endl;
		return nullptr;
	}
	return Util::find<Item>(this->items, [&](const Item* i) { return i->getName() == item; });
}

Item* Scene::take(string& container, string& item)
{
	auto c = take(container);
	if (c == nullptr)
	{
		return c;
	}
	return c->take(item);
}

list<Item*> Scene::takeAll()
{
	if (isDark() && !isIlluminated())
	{
		cout << "It's dark, you can't see anything" << endl;
		return {};
	}
	if(!hasItems())
	{
		cout << "There's nothing here" << endl;
		return{};
	}
	auto result = list<Item*>(this->items);
	this->items.clear();
	return result;
}

Scene::~Scene()
{
	this->paths.clear();
}
