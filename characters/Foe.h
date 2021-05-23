#ifndef ZORK_CHARACTERS_FOE_H
#define ZORK_CHARACTERS_FOE_H

#include <string>
#include "Character.h"

class Foe : public Character
{
public:
	Foe(std::string& name, std::string& description, int& health, int& damage);
	Foe(const Foe&) = delete;
	Foe& operator =(const Foe&) = delete;
	Foe(Foe&&) = delete;
	Foe& operator=(Foe&&) = delete;

	~Foe() override = default;

	void printStats() override;
	Item* getCurrentWeapon() override;
	void dropDead() override;
};

#endif  //ZORK_CHARACTERS_FOE_H
