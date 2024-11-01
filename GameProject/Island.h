#pragma once
#include "Location.h"
class Island :
    public Location
{
private:
    bool found;

public:
    Island();
    void SetFound(bool a);
    bool GetFound();
    void draw();
    int visit(Player& p);
};

