#include "Scene.h"

#include "../Util.h"

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

void Scene::setVisited(const bool visited)
{
	this->visited = visited;
}

void Scene::setIlluminated(const bool isBeingIlluminated)
{
	this->isBeingIlluminated = isBeingIlluminated;
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
				cout << ", but is empty";
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
			if (!isDark() || isIlluminated()) {
				if (enemy->isAlive()) {
					if (visited) {
						cout << "You see a fearsome " << enemy->getName() << endl;
					}
					else
					{
						cout << enemy->getDescription() << " appeared in front of you" << endl;
					}
				}
				else
				{
					cout << "You see the remains of " << enemy->getName() << endl;
				}
			}
		}
	}
}

Scene::~Scene()
{
	this->paths.clear();
}
