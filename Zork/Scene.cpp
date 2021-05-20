#include "Scene.h"

#include "Util.h"

Scene::Scene()
{
	this->dark = false;
}

void Scene::addPath(Direction direction, Scene* scene)
{
	this->paths.insert(make_pair(direction, scene));
}

Scene* Scene::getPath(Direction direction)
{
	return this->paths.at(direction);
}

bool Scene::hasPath(Direction direction)
{
	return this->paths.find(direction) != this->paths.end();
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

void Scene::setDescription(string description)
{
	this->description = description;
}

void Scene::setDark(bool isDark)
{
	this->dark = isDark;
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

string Scene::getBrief()
{
	return "";
}

Item* Scene::take(string& item)
{
	return Util::find<Item>(this->items, [=](const Item* i) { return i->getName() == item; });
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
	auto result = list<Item*>(this->items);
	this->items.clear();
	return result;
}

Scene::~Scene()
{
	this->paths.clear();
}
