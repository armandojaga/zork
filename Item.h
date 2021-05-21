#pragma once
#include <string>
#include <list>
#include <unordered_map>

using namespace std;

enum ItemType
{
	LOCKED_BOX,
	BOX,
	WEAPON,
	LIGHT,
	HEALING,
	RANGE_WEAPON,
	AMMO,
	KEY,
	NORMAL
};

static const unordered_map<std::string, ItemType> itemTypeMap = {
	{"LOCKED_BOX", LOCKED_BOX},
	{"BOX", BOX},
	{"WEAPON", WEAPON},
	{"LIGHT", LIGHT},
	{"HEALING", HEALING},
	{"RANGE_WEAPON", RANGE_WEAPON},
	{"AMMO", AMMO},
	{"KEY", KEY},
	{"NORMAL", NORMAL}
};

class Item
{
private:
	string name;
	ItemType type;
	int magnitude;
	list<Item*> items;
	void remove(Item* item);
	Item* get(string& item);

public:
	Item();
	~Item();
	string getName() const { return this->name; }
	ItemType getType() const { return this->type; }
	int getMagnitude() const { return this->magnitude; }

	void setName(string name);
	void setType(string type);
	void setType(ItemType& type);
	void setMagnitude(int magnitude);

	void add(Item* item);
	Item* take(string& item);
	bool IsContainer() const { return this->type == BOX || this->type == LOCKED_BOX; }
	bool IsLocked() const { return this->type == LOCKED_BOX; }

	bool operator==(Item& other) const { return this->name == other.name; }
	friend bool operator==(Item* item, string _name) { return item->name == _name; }
};
