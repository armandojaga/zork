#include "Scene.h"
#include <utility>

Scene::Scene()
{
	this->isDark = false;
}

void Scene::addPath(Direction direction, Scene* scene)
{
	this->paths.insert(make_pair(direction, scene));
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
	this->description = std::move(description);
}

void Scene::setDark(bool isDark)
{
	this->isDark = isDark;
}

Scene::~Scene() {}
