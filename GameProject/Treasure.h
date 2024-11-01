#pragma once
#include "Location.h"
class Treasure :
    public Location
{
private:
    bool taken;

public:
    Treasure();
    void SetTaken(bool t);
    bool GetTaken();
    void draw();
    int visit(Player& p);
};

