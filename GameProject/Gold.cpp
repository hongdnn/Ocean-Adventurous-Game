#include "Gold.h"

Gold::Gold() :Location('#')
{
	found = false;
}
void Gold::SetFound(bool t) {
	found = t;
}
bool Gold::GetFound() {
	return found;
}

void Gold::draw() {
	if (found) cout << " ";
	else Location::draw();
}

int Gold::visit(Player& p) {
	if (!visited) {
		visited = true;
		cout << "You found a gold." << endl;
        return 1;
	}
	return 0;
}
