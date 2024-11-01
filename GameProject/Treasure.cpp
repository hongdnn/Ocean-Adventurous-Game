#include "Treasure.h"


Treasure::Treasure() :Location('$')
{
	taken = false;
}
void Treasure::SetTaken(bool t) {
	taken = t;
}
bool Treasure::GetTaken() {
	return taken;
}

void Treasure::draw() {
	if (taken) cout << " ";
	else Location::draw();
}

int Treasure::visit(Player& p) {
	if (!visited) {
		visited = true;
		cout << "Congratulations! You found the mysterious treasure!" << endl;
        return 4;
	}
	return 0;
}

