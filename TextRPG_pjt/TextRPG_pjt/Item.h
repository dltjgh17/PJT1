#pragma once
#include "Character.h"

using namespace std;

class Item
{
public:
	virtual ~Item() {}
	virtual void Use(Character* character) = 0;
	virtual const string& getName() const = 0;
};