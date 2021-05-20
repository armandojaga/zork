#pragma once
#include <string>
#include "Character.h"

class Foe: public Character
{
	Foe(string name, string description, int health, int damage);
	virtual ~Foe();
};