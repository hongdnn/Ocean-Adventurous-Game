#pragma once
#include "Player.h"
class Location
{
protected:
	bool visited;
	char symbol;

public:
	Location(char s = ' ');
	void SetVisited(bool v);
	bool GetVisited();
	void SetSymbol(char s);
	char GetSymbol();
	virtual void draw();
	virtual int visit(Player& p);
};

