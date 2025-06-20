#pragma once
#include <string>
using namespace std;

class Item
{
public:
	virtual ~Item() {}
	virtual void Use() = 0;
	virtual const string& getName() const = 0;
};