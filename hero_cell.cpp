#include "hero_cell.h"


Tile* HeroCell::operator+(Hero& p) {
    return new HeroCell();         //���������� ��������� �� ������ � ������� ������ ����� �����
}

Tile* HeroCell::operator-(Hero& p) {
    return new Cell();             //���������� ��������� �� ������ ������, �� ������� �� ������
}

void HeroCell::visit(ostream& out) const {
    out << "H";                    //� ����� ������� ������ �����
}
Tile* HeroCell:: copyElem() {
    return new HeroCell(*this);     //���������� ��������� �� ���� ������ ��� �����������
}


