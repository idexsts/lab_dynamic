#include "wall.h"
#include "exepts.h"

Tile* Wall::operator+(Hero& p) {
	p.lose_hp();
	if (p.lives() <= 0) {
		throw new HpError;
		return new HeroCell();
	}
	else {
		throw new WallError;
		
	}
	
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