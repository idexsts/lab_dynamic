#pragma once
//класс герой (позиция,монетки,хп,перемещение,сбор монетки,потеря хп,стек монет)
#include <iostream>
using namespace std;

class Hero {
	int x, y;  
	int coins=0;
	int hp=5;
public:
	Hero(int _i = 0, int _j = 0) : x(_i), y(_j) {};
	int getX() { return x; }
	int getY() { return y; }
	void move(int _i = 0, int _j = 0) { x = _i; y = _j; }
	void get_coin() { coins++; }
	int stock() { return coins; }
	void lose_hp() { hp--;}
	int lives() { return hp; }
};