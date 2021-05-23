#ifndef ZORK_ITEM_H
#define ZORK_ITEM_H

#include <string>
#include <list>
#include <unordered_map>

enum eItemType
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

static const std::unordered_map<std::string, eItemType> itemTypeMap = {
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
	std::string name;
	eItemType type;
	int magnitude;
	std::list<Item*> items;

	Item* get(std::string& item);

public:
	Item();
	Item(const Item&) = delete;
	Item& operator =(const Item&) = delete;
	Item(Item&&) = delete;
	Item& operator=(Item&&) = delete;

	~Item();

	std::string getName() const { return this->name; }
	eItemType getType() const { return this->type; }
	int getMagnitude() const { return this->magnitude; }
	bool hasItems() const { return !this->items.empty(); }
	std::list<Item*> getItems() const { return this->items; }

	void setName(std::string& name);
	void setType(std::string& type);
	void setType(eItemType& type);
	void setMagnitude(int& magnitude);

	void remove(Item* item);
	void add(Item* item);
	bool IsContainer() const { return this->type == BOX || this->type == LOCKED_BOX || this->type == OPEN_BOX; }
	bool IsLocked() const { return this->type == LOCKED_BOX; }
	bool isWeapon() const { return this->type == WEAPON || this->type == RANGE_WEAPON; }
	bool isAmmo() const { return this->type == AMMO; }
	bool isStory() const { return this->type == STORY; }
};

#endif  //ZORK_ITEM_H
