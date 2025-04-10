#pragma once
//наследник базового класса клетки, обозначающий клетку, в которой тусит герой

#include "tile.h"
#include "empty_cell.h"


class HeroCell : public Tile {
public:
    Tile* operator+(Hero& p);
    Tile* operator-(Hero& p);
    void visit(ostream& out) const;
    Tile* copyElem();
};
