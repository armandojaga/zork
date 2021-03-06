#include "Item.h"
#include "Util.h"

Item::Item()
{
	this->type = NORMAL;
	this->magnitude = 0;
};


void Item::setName(std::string& name)
{
	this->name = name;
}

void Item::setType(std::string& type)
{
	this->type = itemTypeMap.at(type);
}

void Item::setType(eItemType& type)
{
	this->type = type;
}

void Item::setMagnitude(int& magnitude)
{
	this->magnitude = magnitude;
}

void Item::add(Item* item)
{
	if (IsContainer())
	{
		this->items.push_back(item);
	}
}

void Item::remove(Item* item)
{
	this->items.remove(item);
}

Item* Item::get(std::string& item)
{
	return Util::filter<Item*>(this->items, [&](const Item* i) { return i->name == item; }).front();
}

Item::~Item()
{
	this->items.clear();
}
