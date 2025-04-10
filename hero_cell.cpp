#include "hero_cell.h"


Tile* HeroCell::operator+(Hero& p) {
    return new HeroCell();         //возвращает указатель на клетку в которой теперь тусит герой
}

Tile* HeroCell::operator-(Hero& p) {
    return new Cell();             //возвращает указатель на пустую клетку, из которой он пришел
}

void HeroCell::visit(ostream& out) const {
    out << "H";                    //в поток пишется символ героя
}
Tile* HeroCell:: copyElem() {
    return new HeroCell(*this);     //возвращает указатель на саму клетку для копирования
}


