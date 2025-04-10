#pragma once
//��������� �� ��������� ����� ���� ����
#include "tile.h"
#include "hero_cell.h"

class Wall : public Tile {
	Tile* operator+(Hero& p);
	Tile* operator-(Hero& p);
	void visit (ostream& out) const;
	Tile* copyElem();
};
