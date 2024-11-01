#include "Diamond.h"

Diamond::Diamond() :Location('*')
{
	achieved = false;
}
void Diamond::SetAchieved(bool t) {
	achieved = t;
}
bool Diamond::GetAchieved() {
	return achieved;
}

void Diamond::draw() {
	if (achieved) cout << " ";
	else Location::draw();
}

int Diamond::visit(Player& p) {
	if (!visited) {
		visited = true;
		cout << "You found a diamond." << endl;
        return 2;
	}
	return 0;
}
