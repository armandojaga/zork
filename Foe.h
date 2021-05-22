#pragma once
#include <string>
#include "Character.h"

class Foe : public Character
{
public:
	Foe(string& name, string& description, int& health, int& damage);
	~Foe() override;
	void printStats() override;
};
