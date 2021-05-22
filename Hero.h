#pragma once
#include <string>
#include "Character.h"

class Hero : public Character
{
public:
	Hero(string& name, string& description, int& health, int& damage);
	~Hero() override;
	void printStats() override;
	void go(Direction&);
	void attack(string&);
	void take(string&);
	void drop(string&);
	void open(string&);	
};
