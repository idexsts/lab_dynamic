#include "empty_cell.h"

Tile* Cell::operator+(Hero& p) {
    return new HeroCell();      //указатель на новую клетку где тусит герой
}

Tile* Cell::operator-(Hero& p) {
    return new Cell();          //указатель на клетку из которой он ушел
}

void Cell::visit(ostream& out) const {
    out << ".";                //пустую клетку в поток
}

Tile* Cell::copyElem() {
    return new Cell(*this);    //указатель на саму клетку для копирования
}


