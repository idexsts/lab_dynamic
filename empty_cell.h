#pragma once
//��������� �������� ������ ������, ������������ ������ ������

#include "tile.h"
#include "hero_cell.h"

class Cell :public Tile {
public:
    Tile* operator+(Hero& p);
    Tile* operator-(Hero& p);
    void visit(ostream& out) const;
    Tile* copyElem();
};