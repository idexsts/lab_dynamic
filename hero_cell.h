#pragma once
//��������� �������� ������ ������, ������������ ������, � ������� ����� �����

#include "tile.h"
#include "empty_cell.h"


class HeroCell : public Tile {
public:
    Tile* operator+(Hero& p);
    Tile* operator-(Hero& p);
    void visit(ostream& out) const;
    Tile* copyElem();
};
