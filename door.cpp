#include "door.h"

Tile* Door::operator+(Hero& p) {
	//if (p.stock() == 3) {
		//cout << "you won!" << endl;
		return new HeroCell();
	
	//else {
		//cout << "you need more coins!" << endl;
	//}
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