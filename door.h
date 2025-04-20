#pragma once
//класс наследник клетки, дверь (остановите,остановите
//Вите, Вите надо выйти)
#include "tile.h"
#include "hero_cell.h"

class Door : public Tile {
	Tile* operator+(Hero& p);
	Tile* operator-(Hero& p);
	void visit(ostream& out) const;
	Tile* copyElem();
	char getSymbol() {
		return '#';
	}
};