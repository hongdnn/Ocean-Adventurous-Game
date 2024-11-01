#pragma once
#include "Location.h"
class StormArea :
    public Location
{
private:
    bool found;

public:
    StormArea();
    void SetFound(bool f);
    bool GetFound();
    void draw();
    int visit(Player& p);
};

