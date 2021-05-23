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
	OPEN_BOX,
	NORMAL,
	STORY
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
	{"NORMAL", NORMAL},
	{"STORY", STORY}
};

class Item
{
private:
	string name;
	ItemType type;
	int magnitude;
	list<Item*> items;

	Item* get(string& item);

public:
	Item();
	~Item();
	string getName() const { return this->name; }
	ItemType getType() const { return this->type; }
	int getMagnitude() const { return this->magnitude; }
	bool hasItems() const { return !this->items.empty(); }
	list<Item*> getItems() const { return this->items; }

	void setName(string name);
	void setType(string type);
	void setType(ItemType& type);
	void setMagnitude(int& magnitude);

	void remove(Item* item);
	void add(Item* item);
	bool IsContainer() const { return this->type == BOX || this->type == LOCKED_BOX || this->type == OPEN_BOX; }
	bool IsLocked() const { return this->type == LOCKED_BOX; }
	bool isWeapon() const { return this->type == WEAPON || this->type == RANGE_WEAPON; }
	bool isAmmo() const { return this->type == AMMO; }
	bool isStory() const { return this->type == STORY; }

	bool operator==(Item& other) const { return this->name == other.name; }
	friend bool operator==(Item* item, string _name) { return item->name == _name; }
};
