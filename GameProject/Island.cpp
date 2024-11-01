#include "Island.h"


Island::Island() :Location('+')
{
	found = false;
}

void Island::SetFound(bool f) {
	found = f;
}

bool Island::GetFound() {
	return found;
}

void Island::draw() {
	if (found) cout << " ";
	else Location::draw();
}

int Island::visit(Player& p) {
	if (!visited) {
		visited = true;
		cout << "You found the lost people on the island!" << endl;
        return 3;
	}
	return 0;
}

