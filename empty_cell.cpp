#include "empty_cell.h"

Tile* Cell::operator+(Hero& p) {
    return new HeroCell();      //��������� �� ����� ������ ��� ����� �����
}

Tile* Cell::operator-(Hero& p) {
    return new Cell();          //��������� �� ������ �� ������� �� ����
}

void Cell::visit(ostream& out) const {
    out << ".";                //������ ������ � �����
}

Tile* Cell::copyElem() {
    return new Cell(*this);    //��������� �� ���� ������ ��� �����������
}


