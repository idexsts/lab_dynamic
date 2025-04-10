
//становимся богаче

#include "coin.h"

Tile* Coin::operator+(Hero& p) {
	p.get_coin();
	return new HeroCell();
}
Tile* Coin::operator-(Hero& p) {
	return new Cell();
}
void Coin::visit(ostream& out) const {
	out << "$";
}
Tile* Coin::copyElem() {
	return new Coin(*this);
}
