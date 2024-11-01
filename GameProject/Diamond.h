#pragma once
#include "Location.h"
class Diamond :
    public Location
{
private:
    bool achieved;

public:
    Diamond();
    void SetAchieved(bool a);
    bool GetAchieved();
    void draw();
    int visit(Player& p);
};

