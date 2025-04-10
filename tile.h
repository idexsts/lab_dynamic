#pragma once
//абстрактный класс для того чтобы мочь управлять разными типами объектов-клеточек в лабиринте

//визитор чтобы сувать туда объекты наследников и веселиться, ведь он отправится в поток вывода
//определенным образом (в зависимости от типа клетки)
#include <iostream>
#include "hero.h"
using namespace std;

class Tile {
public:
    virtual Tile* operator+(Hero& p) = 0; //указатель на функцию типа Tile, возвращает указатель на объект типа Tile
    virtual Tile* operator-(Hero& p) = 0; //то же самое, что и выше
    virtual void visit(ostream& out) const = 0; // отправляет в поток вывода определенный тип клетки
    friend ostream& operator <<(ostream& out, Tile* c) // возвращает этот поток вывода, в место куда указывает указатель помещается 
    {                                                  //новый элементик
        (*c).visit(out);
        return out;
    }
    virtual Tile* copyElem() = 0; // копирует клеточку 
};