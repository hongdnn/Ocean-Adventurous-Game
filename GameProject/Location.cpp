#include "Location.h"

Location::Location(char s) {
	symbol = s;
 	visited = false;
}

void Location::SetVisited(bool v) {
	visited = v;
}
bool Location::GetVisited() {
	return visited;
}
void Location::SetSymbol(char s) {
	symbol = s;
}
char Location::GetSymbol() {
	return symbol;
}

void Location::draw() {
	if (visited == true) {
		cout << symbol;
	}
	else {
		cout << ".";
	}
}
int Location::visit(Player& p) {
	visited = true;
	return 0;
}
