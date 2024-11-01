#pragma once
#include "Location.h"
class Gold :
    public Location
{
private:
    bool found;

public:
    Gold();
    void SetFound(bool f);
    bool GetFound();
    void draw();
    int visit(Player& p);
};

