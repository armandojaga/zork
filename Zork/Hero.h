#pragma once
#include <string>
#include "Character.h"

class Hero : public Character
{
public:
	Hero(string name, string description, int health, int damage);
	virtual ~Hero();
};