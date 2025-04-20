#include "door.h"
#include "exepts.h"

Tile* Door::operator+(Hero& p) {
	if (p.stock() >= 3) {
		throw new Win;
		return new HeroCell();
	}
	else {
		throw new CoinsError;
	}
}
Tile* Door::operator-(Hero& p) {
	return new Door();
}
void Door::visit(ostream& out) const {
	out << "#";
}
Tile* Door::copyElem() {
	return new Door(*this);
}