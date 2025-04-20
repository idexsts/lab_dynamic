#pragma once
//наследник класса клетки, монетка
#include "empty_cell.h"
#include "tile.h"
#include "hero_cell.h"


class Coin : public Tile {
public:
    Tile* operator+(Hero& p);
    Tile* operator-(Hero& p);
    void visit(ostream& out) const;
    Tile* copyElem();
    char getSymbol() {
        return '$';
    }
};