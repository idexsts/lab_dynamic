#include "wall.h"

Tile* Wall::operator+(Hero& p) {
	p.lose_hp();
	return new HeroCell();
}
Tile* Wall::operator-(Hero& p) {
	return new Cell();
}
void Wall::visit(ostream& out) const {
	out << "X";
}
Tile* Wall::copyElem() {
	return new Wall(*this);
}