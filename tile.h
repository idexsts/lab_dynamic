#pragma once
//����������� ����� ��� ���� ����� ���� ��������� ������� ������ ��������-�������� � ���������

//������� ����� ������ ���� ������� ����������� � ����������, ���� �� ���������� � ����� ������
//������������ ������� (� ����������� �� ���� ������)
#include <iostream>
#include "hero.h"
using namespace std;

class Tile {
public:
    virtual Tile* operator+(Hero& p) = 0; //��������� �� ������� ���� Tile, ���������� ��������� �� ������ ���� Tile
    virtual Tile* operator-(Hero& p) = 0; //�� �� �����, ��� � ����
    virtual void visit(ostream& out) const = 0; // ���������� � ����� ������ ������������ ��� ������
    friend ostream& operator <<(ostream& out, Tile* c) // ���������� ���� ����� ������, � ����� ���� ��������� ��������� ���������� 
    {                                                  //����� ���������
        (*c).visit(out);
        return out;
    }
    virtual Tile* copyElem() = 0; // �������� �������� 
};