#ifndef ZORK_CHARACTERS_HERO_H
#define ZORK_CHARACTERS_HERO_H

#include <string>
#include "Character.h"

class Hero : public Character
{
public:
	Hero(std::string& name, std::string& description, int& health, int& damage);
	Hero(const Hero&) = delete;
	Hero& operator =(const Hero&) = delete;
	Hero(Hero&&) = delete;
	Hero& operator=(Hero&&) = delete;

	~Hero() override = default;

	void printStats() override;
	void go(eDirection&);
	void open(Item&);
	Item* getCurrentWeapon() override;
	void attack(Character& enemy, Item* weapon);
	void dropDead() override;
	bool canEscape() const;
};

#endif  //ZORK_CHARACTERS_HERO_H
