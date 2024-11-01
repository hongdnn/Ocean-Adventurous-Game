#pragma once
#include "Location.h"
class Pirate :
    public Location
{
private:
    bool met;

public:
    Pirate();
    void SetMet(bool f);
    bool GetMet();
    void draw();
    int visit(Player& p);
};

